#include<bits/stdc++.h>
#pragma GCC optimize("-Ofast")
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1000010;
char buf[1<<20],obuf[1<<20],*p1,*p2,*p3=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
inline ll read(){
    ll x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
#define lc k<<1
#define rc lc|1
#define mid (l+r>>1)
#define fi first
#define se second
#define sot(x) sort(x.begin(),x.end())
int n,c[N],qx[N],qm[N],cx,cm,px[N],pm[N],t1,t2,V[N];
struct BIT{
	int A[N],B[N],R;
	int QRY(int*U,int x){for(R=0;x;x&=(x-1))R+=U[x];return R;}
	int qry(int l,int r){
		return r*QRY(A,r)-(l-1)*QRY(A,l-1)-(QRY(B,r)-QRY(B,l-1));
	}
	void UPD(int*U,int x,int v){for(;x<=n;x+=(x&-x))U[x]+=v;}
	void upd(int l,int r,int v){
		UPD(A,l,v),UPD(A,r+1,-v),UPD(B,l,v*(l-1)),UPD(B,r+1,-v*r);
	}
	void clear(){memset(A,0,sizeof A),memset(B,0,sizeof B);}
}t[2];
ll a[N],ans,sum;
vector<pii>ex[62],em[62];
void mdf(int w,int l,int r,int v){sum+=v*t[!w].qry(l,r),t[w].upd(l,r,v);}
signed main(){
	FOR(i,1,n=read()){
		V[c[i]=__builtin_popcountll(a[i]=read())]=1;
		while(cx&&a[i]>a[qx[cx]])ex[c[qx[cx]]].pbk({i,qx[cx--]});
		px[i]=qx[cx]+1,qx[++cx]=i;
		while(cm&&a[i]<a[qm[cm]])em[c[qm[cm]]].pbk({i,qm[cm--]});
		pm[i]=qm[cm]+1,qm[++cm]=i;
	}
	FOR(w,0,60)if(V[w]){
		sot(ex[w]),sot(em[w]);
		t[t1=t2=sum=0].clear(),t[1].clear();
		rgi S1=ex[w].size(),S2=em[w].size();
		FOR(i,1,n){
			if(c[i]==w)mdf(0,px[i],i,1),mdf(1,pm[i],i,1);
			while(t1<S1&&ex[w][t1].fi==i){
				rgi k=ex[w][t1++].se;
				mdf(0,px[k],k,-1);
			}
			while(t2<S2&&em[w][t2].fi==i){
				rgi k=em[w][t2++].se;
				mdf(1,pm[k],k,-1);
			}
			ans+=sum;
		}
	}
	printf("%lld",ans);
	return 0;
}