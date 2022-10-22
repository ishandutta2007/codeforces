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

const int N=1e6+99;

int n,t,a[N];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		map<int,int> mark;
		vector<int> v1,v2;
		cin>>n;
		int ans=n;
		f(i,0,n){
			int x;
			cin>>x;
			if(x<=n && !mark[x]){
				mark[x]=1;
				ans--;
			}
			else{
				int mx=min(n,(x-1)/2);
				v2.pb(mx);
			}
		}
		f(i,1,n+1){
			if(!mark[i]){
				v1.pb(i);
			}
		}
		sort(all(v1));
		sort(all(v2));
		f(i,0,v1.size()){
			if(v1[i]>v2[i]){
				ans=-1;
			}
		}
		cout<<ans<<endl;
	}
}