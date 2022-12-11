#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
char ch[210000];
int n,m,height[210000][17],c[210000],sa[210000],rank[210000],x[210000],y[210000],Log2[210000],L[100],f[210000],A[210000][26];
long long w[100],cnt[210000],now;
struct atom{
	int r,w;
};
int operator < (const atom k1,const atom k2){
	return k1.r>k2.r;
}
priority_queue<atom>Q;
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
	if (k1>k2) swap(k1,k2);
    int k3=Log2[k2-k1]; return min(height[k2][k3],height[k1+(1<<k3)][k3]);
}
int equal(int k1,int k2,int k3){
	return findmin(rank[k1],rank[k2])>=k3;
}
#define sqr(x) ((x)*(x))
void find(int l,int r,int cha,int w1,int w2){
	int len=r-l+1; now+=sqr(1ll*len);
	int k1=l-1-len,k2=k1+(cha-l),k3=ch[l-1]-'a'; //if (l==5&&r==5&&w2=='j') cout<<k1<<" "<<k2<<" "<<k3<<" "<<ch+1<<" "<<ch[l-1]<<endl;
	if (k1>0&&equal(k1,l,cha-l)&&equal(cha+1,k2+1,r-cha)&&ch[cha]==ch[k2]&&A[l-2][k3]==A[k1-1][k3]){
		 int num=A[r][k3]-A[l-1][k3]+(w2==ch[l-1])-(w1==ch[l-1]);
		 if (num==0) find(k1,r,cha,w1,w2);
	}
	k1=r+1+len,k2=k1-(r-cha),k3=ch[r+1]-'a';
	if (k1<=n&&equal(l,r+2,cha-l)&&equal(cha+1,k2+1,r-cha)&&ch[cha]==ch[k2]&&A[k1][k3]==A[r+1][k3]){
		 int num=A[r][k3]-A[l-1][k3]+(w2==ch[r+1])-(w1==ch[r+1]);
		 if (num==0) find(l,k1,cha,w1,w2);
	}
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%s",ch+1); n=strlen(ch+1);
	for (int i=1;i<=n;i++){
		memcpy(A[i],A[i-1],sizeof A[i-1]);
		A[i][ch[i]-'a']++;
	}
	for (int i=1;i<=n;i++) x[i]=ch[i]; m=200; make();
	for (int i=1;i<=16;i++)
		for (int j=(1<<i);j<=n;j++) height[j][i]=min(height[j][i-1],height[j-(1<<i-1)][i-1]);
    for (int i=1;i<=n;i++) Log2[i]=trunc(log(i)/log(2)+1e-6);
    int len=1; L[1]=1; while (L[len]<=n){len++; L[len]=L[len-1]*2+1;} len--;
    for (int i=1;i<=len;i++) w[i]=1ll*L[i]*L[i];
    for (int i=1;i<=len;i++) w[i]+=w[i-1];
    for (int i=1;i<=n;i++) f[i]=1;
    for (int i=2;i<=len;i++)
    	for (int j=L[i-1]+1;j<=n-L[i-1];j++){
    		if (f[j]!=i-1) continue;
    		int l=j-L[i-2]-1,r=j+L[i-2]+1;
    		if (f[l]<i-1||f[r]<i-1) continue;
    		l=j-L[i-1],r=j+1; int k1=ch[j]-'a'; //if (i==3) cout<<l<<" "<<r<<" "<<equal(l,r,L[i-1])<<" "<<A[j-1][k1]<<" "<<A[l-1][k1]<<" "<<A[j+L[i-1]][k1]<<" "<<A[j][k1]<<endl;
    		if (equal(l,r,L[i-1])&&(A[j-1][k1]-A[l-1][k1]==0)&&(A[j+L[i-1]][k1]-A[j][k1]==0)) f[j]=i;
    	}
    long long num=0,ans=0;
    for (int i=1;i<=n;i++) num+=w[f[i]];
    now=0;
    for (int i=1;i<=n;i++){
    	while (!Q.empty()&&Q.top().r<i){now-=sqr(1ll*Q.top().w); Q.pop();}
    	for (int j=1;j<=len;j++){
    		int k1=i+L[j-1]; if (k1<=n&&f[k1]>=j){now+=sqr(1ll*L[j]); Q.push((atom){i+L[j]-1,L[j]});};
    	}
    	cnt[i]=now;
    }
	//for (int i=1;i<=n;i++) cout<<f[i]<<" "<<cnt[i]<<endl; cout<<num<<endl;
    for (int i=1;i<=n;i++){
    	int pre=ch[i];
    	for (int j='a';j<='z';j++){
    		ch[i]=j; now=num-cnt[i]; find(i,i,i,pre,j); //if (i==6&&j=='b') cout<<now<<" "<<endl;
    		for (int k1=2;k1<=len;k1++){
    			int l=i-L[k1-1],r=i+L[k1-1],lmid=l+L[k1-2],rmid=r-L[k1-2]; //if (i==6&&j=='b')cout<<l<<" "<<r<<" "<<A[i-1][j-'a']<<" "<<A[l-1][j-'a']<<" "<<A[i][j-'a']<<" "<<A[r][j-'a']<<" "<<lmid<<" "<<rmid<<" "<<k1-1<<endl;
    			if (l>0&&r<=n&&equal(l,i+1,L[k1-1])&&f[lmid]>=k1-1&&f[rmid]>=k1-1&&A[i-1][j-'a']==A[l-1][j-'a']&&A[i][j-'a']==A[r][j-'a']) find(l,r,i,pre,j);
    		//	if (i==6&&j=='b') cout<<k1<<" "<<now<<endl;
    		}
    		ans=max(ans,now);// if (i==6&&j=='b') cout<<now<<endl;
    	}
    	ch[i]=pre;
    }
    cout<<ans<<endl;
	return 0;
}