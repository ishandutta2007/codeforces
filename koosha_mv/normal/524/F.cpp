#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e6+99,mod=1e9+7,base=5;

int n,t,c0,c1,res,ps[N],h[N],Pow[N];
string s;
set<pair<int,int>> st;

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void pre(){
	Pow[0]=1;
	f(i,1,2*n+1) Pow[i]=1ll*Pow[i-1]*base%mod;
	f(i,1,2*n+1){
		h[i]=(h[i-1]+(s[i]-'(')*Pow[i])%mod;
	}
}
int get(int l,int r){
	return (h[r]-h[l-1]+mod)*Pow[n-l]%mod;
}
bool cmp(int p1,int p2){
	int l=-1,r=n-1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(get(p1,p1+mid)==get(p2,p2+mid)) l=mid;
		else r=mid;
	}
	return s[p1+r]<s[p2+r];
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>s;
	n=s.size();
	s='s'+s+s;
	f(i,1,n+1) c0+=(s[i]=='('),c1+=(s[i]==')');
	f(i,1,2*n+1) ps[i]=ps[i-1]+(s[i]=='(' ? +1 : -1);
	f(i,n+1,2*n+1) st.insert({ps[i],i});
	pre();
	f_(i,n,1){
		st.insert({ps[i],i});
		st.erase({ps[i+n],i+n});
		int mn=(*st.begin()).F-ps[i-1];
		if(mn>=0 || (-mn)<=c1-c0){
			//eror(i);
			if(res==0 || cmp(i,res)){
				//eror(2);
				res=i;
			}
		}
	}
	string ans;
	f(i,0,c1-c0) ans+='(';
	f(i,res,res+n) ans+=s[i];
	f(i,0,c0-c1) ans+=')';
	cout<<ans;
}