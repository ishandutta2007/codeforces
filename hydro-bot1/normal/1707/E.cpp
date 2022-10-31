// Hydro submission #62de8d8b25d42d0516203685@1658752395881
#include<bits/stdc++.h>
using namespace std;
namespace my_std{
	#define ll long long
	#define bl bool
	ll my_pow(ll a,ll b,ll mod){
		ll res=1;
		if(!b) return 1;
		while(b){
			if(b&1) res=(res*a)%mod;
			a=(a*a)%mod;
			b>>=1;
		}
		return res;
	}
	ll qpow(ll a,ll b){
		ll res=1;
		if(!b) return 1;
		while(b){
			if(b&1) res*=a;
			a*=a;
			b>>=1;
		}
		return res;
	}
	#define db double
	#define pf printf
	#define pc putchar
	#define fr(i,x,y) for(register ll i=(x);i<=(y);i++)
	#define pfr(i,x,y) for(register ll i=(x);i>=(y);i--)
	#define go(u) for(ll i=head[u];i;i=e[i].nxt)
	#define enter pc('\n')
	#define space pc(' ')
	#define fir first
	#define sec second
	#define MP make_pair
	#define il inline
	#define inf 8e18
	#define random(x) rand()*rand()%(x)
	#define inv(a,mod) my_pow((a),(mod-2),(mod))
	il ll read(){
		ll sum=0,f=1;
		char ch=0;
		while(!isdigit(ch)){
			if(ch=='-') f=-1;
			ch=getchar();
		}
		while(isdigit(ch)){
			sum=sum*10+(ch^48);
			ch=getchar();
		}
		return sum*f;
	}
	il void write(ll x){
		if(x<0){
			x=-x;
			pc('-');
		}
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
	il void writeln(ll x){
		write(x);
		enter;
	}
	il void writesp(ll x){
		write(x);
		space;
	}
}
using namespace my_std;
#define LC x<<1
#define RC x<<1|1
ll n,q,a[100010],lg[100010],minn[19][100010][19],maxx[19][100010][19];
ll querymin(ll t,ll l,ll r){
	if(l>=r) return n+1;
	r--;
	ll tmp=lg[r-l+1];
	return min(minn[t][l][tmp],minn[t][r-(1ll<<tmp)+1][tmp]);
}
ll querymax(ll t,ll l,ll r){
	if(l>=r) return 0;
	r--;
	ll tmp=lg[r-l+1];
	return max(maxx[t][l][tmp],maxx[t][r-(1ll<<tmp)+1][tmp]);
}
int main(){
	n=read();
	q=read();
	fr(i,1,n) a[i]=read();
	lg[1]=0;
	fr(i,2,n) lg[i]=lg[i>>1]+1;
	fr(i,1,n-1){
		minn[0][i][0]=min(a[i],a[i+1]);
		maxx[0][i][0]=max(a[i],a[i+1]);
	}
	fr(j,1,18){
		fr(i,1,n-(1ll<<j)){
			minn[0][i][j]=min(minn[0][i][j-1],minn[0][i+(1ll<<(j-1))][j-1]);
			maxx[0][i][j]=max(maxx[0][i][j-1],maxx[0][i+(1ll<<(j-1))][j-1]);
		}
	}
	fr(t,1,18){
		fr(i,1,n-1){
			minn[t][i][0]=querymin(t-1,minn[t-1][i][0],maxx[t-1][i][0]);
			maxx[t][i][0]=querymax(t-1,minn[t-1][i][0],maxx[t-1][i][0]);
		}
		fr(j,1,18){
			fr(i,1,n-(1ll<<j)){
				minn[t][i][j]=min(minn[t][i][j-1],minn[t][i+(1ll<<(j-1))][j-1]);
				maxx[t][i][j]=max(maxx[t][i][j-1],maxx[t][i+(1ll<<(j-1))][j-1]);
			}
		}
	}
	while(q--){
		ll l=read(),r=read(),ans=0;
		if(l==1&&r==n){
			writeln(0);
			continue;
		}
		pfr(i,18,0){
			if(l==r) break;
			ll nmin=querymin(i,l,r),nmax=querymax(i,l,r);
			if(nmin!=1||nmax!=n){
				l=nmin;
				r=nmax;
				ans+=(1ll<<i);
			}
		}
		if(l==r||querymin(0,l,r)!=1||querymax(0,l,r)!=n) writeln(-1);
		else writeln(ans+1);
	}
}