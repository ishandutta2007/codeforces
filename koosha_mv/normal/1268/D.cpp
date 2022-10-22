#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
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

const int N=2222;

int n,t,ans,cnt,a[N];
string s[N];
bitset<N> mask,g[N];

void change(int x){
	f(i,0,n) g[i][x]=g[i][x]^1,g[x][i]=g[x][i]^1;
}
bool strongly(){
	vector<int> vec,v[N];
	f(i,0,n) v[g[i].count()].pb(i);
	f_(i,n-1,0) for(auto x : v[i]) vec.pb(x);
	f(i,0,n) mask[i]=1;
	f(i,0,vec.size()-1){
		mask&=g[vec[i]];
		if(mask.count()==n-i-1){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n) cin>>s[i];
	f(i,0,n) f(j,0,n) g[i][j]=s[i][j]-'0';
	
	if(n<=6){
		ans=N;
		f(mask,0,(1<<n)){
			f(i,0,n){
				if(mask&(1<<i)){
					change(i);
				}
			}
			if(strongly()){
				if(nb(mask)<ans){
					cnt=0;
					ans=nb(mask);
				}
				if(ans==nb(mask)){
					cnt++;
				}
			}
			f(i,0,n){
				if(mask&(1<<i)){
					change(i);
				}
			}
		}
		if(ans==N) cout<<-1;
		else cout<<ans<<" "<<cnt*max(1,ans);
		return 0;
	}
	if(strongly()){
		return cout<<0<<" "<<1,0;
	}
	f(i,0,n){
		int res1,res2;
		change(i);
		if(strongly()) ans++;
		change(i);
	}
	cout<<1<<" "<<ans;
}