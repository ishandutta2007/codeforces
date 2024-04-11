#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
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

const int N=1e6+99,inf=1e15;

int n,t,k,a[N];

int calc(vector<int> v){
	if(v.size()==0) return 0;
	int i=v.size()-1,ans=0;
	while(i>=0){
		ans+=v[i];
		i-=k;
	}
	return ans;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		vector<int> v0,v1,v2;
		int ans=inf,res1=-inf,res2=-inf;
		cin>>n>>k;
		f(i,0,n){
			int x;
			cin>>x;
			if(x<0) v0.pb(-x);
			else v1.pb(x);
		}
		sort(v0.begin(),v0.end());
		sort(v1.begin(),v1.end());
		if(v0.size()) res1=v0.back();
		if(v1.size()) res2=v1.back();
		cout<<2*(calc(v0)+calc(v1))-max(res1,res2)<<endl;
	}
}