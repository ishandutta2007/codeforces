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

const int N=1e3+99,K=21;

int n,k,is0,ans,cnt[N],sum[N];
vector<int> a[N];
map<vector<int>,int> mark;

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k;
	f(i,0,n){
		f(j,0,k){
			int x;
			cin>>x;
			a[i].pb(x);
			sum[i]+=a[i][j];
		}
		mark[a[i]]=i;
		if(sum[i]==0) is0=1;
	}
	f(i,0,n){
		f(j,i+1,n){
			vector<int> vec;
			f(p,0,k){
				vec.pb((3-(a[i][p]+a[j][p])%3)%3);
			}
			if(mark.count(vec)){
				cnt[mark[vec]]++;
			}
		}
	}
	f(i,0,n){
		if(sum[i]!=0 && is0==1){
			//eror(i);
			//cnt[i]--;
			//eror(cnt[i]);
		}
		ans+=1ll*cnt[i]*(cnt[i]-1)/2;
	}
	cout<<ans;
}