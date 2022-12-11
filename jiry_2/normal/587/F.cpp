#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=210000;
int height[N][18],sa[N],rank[N],x[N],y[N],c[N],tot,n,m,Log2[N],where[N],ch[N],Le[N],fir[N],Q,len;
int L[N],R[N],A[N],B[N];
long long ans[N];
char s[N];
struct ask{
	int where,l,w,K;
}q[N];
void make(){
    for (int i=1;i<=m;i++) c[i]=0;
    for (int i=1;i<=n;i++) c[x[i]]++;
    for (int i=1;i<=m;i++) c[i]+=c[i-1];
    for (int i=n;i;i--){sa[c[x[i]]]=i; c[x[i]]--;} int k=1;
    while (k<=n){
        int p=0;
        for (int i=n-k+1;i<=n;i++){p++; y[p]=i;}
        for (int i=1;i<=n;i++) if (sa[i]>k){p++; y[p]=sa[i]-k;}
        for (int i=1;i<=m;i++) c[i]=0;
        for (int i=1;i<=n;i++) c[x[y[i]]]++;
        for (int i=1;i<=m;i++) c[i]+=c[i-1];
        for (int i=n;i;i--){sa[c[x[y[i]]]]=y[i]; c[x[y[i]]]--;}
        memcpy(y,x,sizeof y); p=1; x[sa[1]]=1;
        for (int i=2;i<=n;i++){
            if (y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k]) p++; x[sa[i]]=p;}
        if (p>=n) break; m=p; k*=2;
    }
    for (int i=1;i<=n;i++) rank[sa[i]]=i;
    k=0;
    for (int i=1;i<=n;i++){
        if (k) k--;
        if (rank[i]==1) continue;
        int k1=sa[rank[i]-1];
        while (ch[i+k]==ch[k1+k]) k++;
        height[rank[i]][0]=k;
    }
}
int findmin(int k1,int k2){
    int k3=Log2[k2-k1]; return min(height[k2][k3],height[k1+(1<<k3)][k3]);
}
int compare(ask k1,ask k2){
	return Le[k1.K]>Le[k2.K]||(Le[k1.K]==Le[k2.K]&&k1.K<k2.K)||(Le[k1.K]==Le[k2.K]&&k1.K==k2.K&&k1.l<k2.l);
}
int compare1(ask k1,ask k2){
	return k1.l<k2.l;
}
const int lim=300;
void solve(int l,int r,int K){
//	cout<<"solve "<<l<<" "<<r<<" "<<K<<endl;
//	for (int i=l;i<=r;i++) cout<<q[i].l<<" "<<q[i].w<<" "<<q[i].K<<" "<<q[i].where<<endl;
	memset(A,0x00,sizeof A);
	for (int i=1;i<=n;i++) if (where[i]==K) A[rank[i]]=1;
	for (int i=1;i<=n;i++) A[i]+=A[i-1]; 
	int now=l; long long to=0;
	for (int i=1;i<=tot;i++){
		to+=A[R[i]]-A[L[i]-1]; 
		while (now<=r&&q[now].l==i) ans[q[now].where]+=q[now].w*to,now++;
	}
}
void insert(int k1,int k2){
//	cout<<"add "<<k1<<" "<<k2<<endl;
	int k3=k1/lim;
	for (int i=0;i<k3;i++) B[i]+=k2;
	k3=k3*lim;
	for (int i=k3;i<=k1;i++) A[i]+=k2;
}
int find(int k1){
//	cout<<"find "<<k1<<" "<<A[k1]+B[k1/lim]<<endl;
	return A[k1]+B[k1/lim];
}
int main(){
	scanf("%d%d",&tot,&Q);
	for (int i=1;i<=tot;i++){
		scanf("%s",s+1); int len=strlen(s+1); Le[i]=len; fir[i]=n+1;
		for (int j=1;j<=len;j++) ch[++n]=s[j],where[n]=i;
		ch[++n]=i+200;
	}
	m=110000;
	for (int i=1;i<=n;i++) x[i]=ch[i]; make();
    for (int i=1;i<=n;i++) Log2[i]=trunc(log(i)/log(2)+1e-6);
    for (int i=1;i<=17;i++)
        for (int j=1;j<=n;j++)
            if ((1<<i)<j) height[j][i]=min(height[j][i-1],height[j-(1<<i-1)][i-1]);
    for (int i=1;i<=tot;i++){
    	int l=1,r=rank[fir[i]]; L[i]=rank[fir[i]];
    	while (l<r){
    		int mid=l+r>>1;
    		if (findmin(mid,rank[fir[i]])>=Le[i]){
    			L[i]=mid; r=mid;
    		} else l=mid+1;
    	}
    	l=rank[fir[i]]+1; r=n+1; R[i]=rank[fir[i]];
    	while (l<r){
    		int mid=l+r>>1;
    		if (findmin(rank[fir[i]],mid)>=Le[i]){
    			R[i]=mid; l=mid+1;
    		} else r=mid;
    	}
    }
    len=0;
    for (int i=1;i<=Q;i++){
    	int l,r,K; scanf("%d%d%d",&l,&r,&K);
    	if (l>1) q[++len]=(ask){i,l-1,-1,K};
    	q[++len]=(ask){i,r,1,K};
    }
    sort(q+1,q+len+1,compare);
    int pre=1;
    for (int i=2;i<=len+1&&Le[q[pre].K]>lim;i++)
    	if (i>len||q[i].K!=q[i-1].K){
    		solve(pre,i-1,q[pre].K); pre=i;
    	}
    sort(q+pre,q+len+1,compare1);
  //  for (int i=pre;i<=len;i++) cout<<"fa "<<q[i].l<<" "<<q[i].w<<" "<<q[i].K<<" "<<q[i].where<<endl;
    memset(A,0x00,sizeof A);
	memset(B,0x00,sizeof B);
	for (int i=1;i<=tot;i++){
		insert(R[i],1); insert(L[i]-1,-1);
		while (pre<=len&&q[pre].l==i){
			for (int j=fir[q[pre].K];j<fir[q[pre].K]+Le[q[pre].K];j++){
			//	cout<<"fafafa "<<q[pre].K<<" "<<j<<" "<<rank[j]<<endl;
				ans[q[pre].where]+=q[pre].w*find(rank[j]);
			}
			pre++;
		}
	}
    for (int i=1;i<=Q;i++) printf("%I64d\n",ans[i]);
    return 0;
}