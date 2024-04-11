#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=2e6+99;

int n,mod,b[N];
vector<int> vec[N];

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>mod;
	f(i,1,n+1){
		int k;
		cin>>k;
		f(j,0,k){
			int x;
			cin>>x;
			x--;
			vec[i].pb(x);
		}
	}
	f(i,1,n){
		int p=-1;
		f(j,0,min(vec[i].size(),vec[i+1].size())){
			if(vec[i][j]!=vec[i+1][j]){
				p=j;
				break;
			}
		}
		if(p==-1){
			if(vec[i].size()>vec[i+1].size()) return cout<<-1,0;
			b[0]++,b[mod]--;
			continue ;	
		}
		int u=vec[i][p],v=vec[i+1][p];
		if(u<v){
			b[mod-u]++;
			b[mod+mod-v]--;
		}
		else{
			b[mod-u]++;
			b[mod-v]--;
		}
	}
	f(i,1,2*mod){
		b[i]+=b[i-1];
	}
	f(i,0,mod){
		if(b[i]+b[i+mod]==n-1){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}