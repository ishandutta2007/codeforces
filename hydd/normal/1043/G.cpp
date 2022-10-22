#include<bits/stdc++.h>
using namespace std;
const int N=410000;
char s[N];
int n,Q,blo,k,Log2[N],pos[N][26],pre[N],nxt[N],mn[N];
struct SA{
	int f[N],g[N],a[N],h[N],val[20][N];
	int sa[N],rk[N],oldrk[N];
	void build(){
		memset(f,0,sizeof(f)); int t;
		for (int i=1;i<=n;i++) f[s[i]-'a'+1]=1;
		for (int i=1;i<=26;i++) f[i]+=f[i-1]; t=f[26];
		for (int i=1;i<=n;i++) rk[i]=f[s[i]-'a'+1];
		for (int i=1;i<n;i<<=1){
			for (int j=1;j<=n;j++) oldrk[j]=rk[j];
			for (int j=1;j<=n;j++) a[j]=j+i<=n?rk[j+i]:0;
			
			memset(f,0,sizeof(f));
			for (int j=1;j<=n;j++) f[a[j]]++;
			for (int j=1;j<=t;j++) f[j]+=f[j-1];
			for (int j=1;j<=n;j++) g[f[a[j]]--]=j;
			
			memset(f,0,sizeof(f));
			for (int j=1;j<=n;j++) f[rk[j]]++;
			for (int j=1;j<=t;j++) f[j]+=f[j-1];
			for (int j=n;j>=1;j--) sa[f[rk[g[j]]]--]=g[j];
			
			t=0;
			for (int j=1;j<=n;j++){
				t+=oldrk[sa[j]]>oldrk[sa[j-1]]||(oldrk[sa[j]]==oldrk[sa[j-1]]&&a[sa[j]]>a[sa[j-1]]);
				rk[sa[j]]=t;
			}
		}
		for (int j=1;j<=n;j++) sa[rk[j]]=j;
		int j=0;
		for (int i=1;i<=n;i++){
			if (rk[i]==n) j=0;
			else{
				if (j) j--;
				while (s[i+j]==s[sa[rk[i]+1]+j]) j++;
			}
			h[rk[i]]=j;
		}
		
		for (int i=1;i<=n;i++) val[0][i]=h[i];
		for (int j=1;(1<<j)<=n;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				val[j][i]=min(val[j-1][i],val[j-1][i+(1<<(j-1))]);
	}
	int lcp(int x,int y){
		x=rk[x]; y=rk[y];
		if (x>y) swap(x,y);
		y--; int k=Log2[y-x+1];
		return min(val[k][x],val[k][y-(1<<k)+1]);//+1?
	}
} A,B;
struct US{
	int fa[N],val[N];
	void init(){
		for (int i=1;i<=n;i++) fa[i]=i,val[i]=n+1;
	}
	int findset(int x){
		if (x!=fa[x]) fa[x]=findset(fa[x]);
		return fa[x];
	}
	void work(int v,int l,int r){
		v<<=1; l=findset(l); r=findset(r);
		while (l!=r){
			val[l]=v;
			fa[l]=l+1; l=findset(l);
		}
	}
} L,R;
int calc(int l,int r){
	bool flag=false;
	for (int i=0;i<26;i++)
		if (nxt[pos[l][i]]<=r) flag=true;
	if (!flag) return -1;


	int len=r-l+1,x=len;
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			int y=len/i;
			if (A.lcp(l,l+y)>=len-y) return 1;
			while (x%i==0) x/=i;
		}
	if (x!=1){
		int y=len/x;
		if (A.lcp(l,l+y)>=len-y) return 1;
	}

	if (L.val[l]<=len||R.val[r]<=len) return 2;
	for (int i=1;i<=blo+1&&r-i+1>l;i++)
		if (A.lcp(l,r-i+1)>=i) return 2;
	for (int i=max(A.rk[l]-blo,1);i<=min(A.rk[l]+blo,n);i++){
		int x=A.sa[i];
		if (l<x&&x<=r&&A.lcp(l,x)>=r-x+1) return 2;
	}

	if (nxt[l]<=r||pre[r]>=l) return 3;
	if (mn[l]<=r) return 3;
	return 4;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n; blo=sqrt(n);
	for (int i=1;i<=n;i++) cin>>s[i];
	cin>>Q; Log2[0]=-1;
	for (int i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
	A.build(); reverse(s+1,s+n+1); B.build(); reverse(s+1,s+n+1);
	L.init(); R.init();
//	A.lcp(8,9);
	for (int len=1;len<=n/2;len++)
		for (int i=len,j=len<<1;j<=n;i+=len,j+=len){
			int lcp=min(A.lcp(i,j),len),lcs=min(B.lcp(n-i+2,n-j+2),len-1);
			int t=lcp+lcs-len+1;
			if (t>0){
				R.work(len,j+lcp-t,j+lcp);
				L.work(len,i-lcs,i-lcs+t);
			}
		}

	mn[n+1]=n+1;
	for (int i=n;i>=1;i--) mn[i]=min(mn[i+1],i+L.val[i]-1);

	for (int c=0;c<26;c++) pos[n+1][c]=n+1;
	for (int i=n;i>=1;i--){
		for (int c=0;c<26;c++) pos[i][c]=pos[i+1][c];
		nxt[i]=pos[i][s[i]-'a']; pre[pos[i][s[i]-'a']]=i;
		pos[i][s[i]-'a']=i;
	}
	nxt[n+1]=n+1;
	 
	int l,r;
	while (Q--){
		cin>>l>>r;
		cout<<calc(l,r)<<endl;
	}
	return 0;
}