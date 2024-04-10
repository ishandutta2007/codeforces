#include<bits/stdc++.h>
using namespace std;
#define rgi register int
typedef long long ll;
const int N=50010,SZ=1500010,W=30;
#define g(x) ((x)>>d&1)
ll n,k,ans,res,M,L,R=(1<<W)-1;
int a[N],ch[SZ][2],siz[SZ],s[SZ][W+1],rt,tot;
void add(int x,int i){
	for(rgi d=W;~d;--d)ans+=(ll)(g(x)?siz[i]-s[i][d]:s[i][d])<<d;
}
void ins(int x,int& r=rt,int d=W){
	++siz[r?r:r=++tot];
	for(rgi D=W;~D;--D)s[r][D]+=(x>>D&1);
	if(~d)ins(x,ch[r][g(x)],d-1);
}
int qry(int x,int r=rt,int d=W){
	return r?!g(M)*siz[ch[r][!g(x)]]+qry(x,ch[r][g(x^M)],d-1):0;
}
void calc(int x,int r=rt,int d=W){
	if(r)calc(x,ch[r][g(x^R)],d-1);
	if(r&&!g(R))add(x,ch[r][!g(x)]);
}
signed main(){
	cin>>n>>k,k<<=1;
	for(rgi i=1;i<=n;++i)cin>>a[i],ins(a[i]);
	while(R>L+1){
		res=0,M=L+R>>1;
		for(rgi i=1;i<=n;++i)res+=qry(a[i]);
		if(res>=k)L=M;
		else R=M,ans=(k-res)*R;
	}
	for(rgi i=1;i<=n;++i)calc(a[i]);
	cout<<(ans/2)%1000000007;
	return 0;
}