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

const int N=1e5+99,mod=1e9+7,Z=26;

int n,q,kmpcnt,f[30*N],K[N],cnt[N][Z],Pow[N],ans[N];
string s,t,in[N];
vector<int> Q[N];

string rev(string s){
	reverse(all(s));
	return s;
}
vector<int> kmp(string p,string s){
	int n=p.size(),m=s.size(),sz=n+m;
	vector<int> vec(n+1);
	s=p+'#'+s,kmpcnt=0;
	f(i,1,s.size()){
		f[i]=f[i-1];
		while(f[i]!=0 && s[i]!=s[f[i]]){
			f[i]=f[f[i]-1];
		}
		if(s[i]==s[f[i]]) f[i]++;
		if(f[i]==n) kmpcnt++;
	}
	while(1){
		vec[f[sz]]=1;
		if(f[sz]==0) break; 
		f[sz]=f[f[sz]-1];
	}
	return vec;
}
int solve(string &p,string &s,vector<ll> &cnt){
	int ans=0;
	vector<int> pfx=kmp(p,s),sfx=kmp(rev(p),rev(s));
	ans=1ll*kmpcnt*cnt[Z]%mod;
	f(i,0,pfx.size()-1){
		if(pfx[i] && sfx[p.size()-i-1]){
			Add(ans,cnt[p[i]-'a']);
		}
	}
	return ans;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Max=0;
	Pow[0]=1;
	f(i,1,N) Pow[i]=2ll*Pow[i-1]%mod;
	cin>>n>>q>>s>>t;
	f(i,0,q){
		cin>>K[i]>>in[i];
		f(j,0,min(22,n+1)){
			if(in[i].size()<(1ll<<j)*(s.size()+1)){
				if(K[i]>=j) Q[j].pb(i),maxm(Max,j);
				break;
			}
		}
	}
	f(i,0,n){
		Add(cnt[i+1][t[i]-'a'],1);
		f(j,0,Z) Add(cnt[i+1][j],2ll*cnt[i][j]%mod);
	}
	f(i,0,Max+1){
		for(auto id : Q[i]){
			string p=in[id];
			int k=K[id];
			vector<ll> ted(Z+1);
			ted[Z]=Pow[k-i];
			f(j,0,Z) ted[j]=cnt[k][j];
			f(j,0,i) Add(ted[t[j]-'a'],mod-Pow[k-j-1]);
			ans[id]=solve(p,s,ted);
		}
		if(i<t.size()) s=s+t[i]+s;	
	}
	f(i,0,q) cout<<ans[i]<<" ";
}