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
#define int ll

const int N=1e6+99,inf=1e16;

int n,m,k,t,ans,a[N];
vector<int> v[N];

int calc(vector<int> &v,int s){
	int sum=0,res=-inf,mv=0;
	vector<int> vec;
	f(i,0,v.size()){
		sum+=v[i];
		vec.pb((-v[i])-v[i]);
	}
	sort(all(vec),greater<int>());
	f(i,0,vec.size()+1){
		if((i&1)==s) maxm(res,mv);
		if(i==vec.size()) break;
		mv+=vec[i];
	}
	return sum+res;
}
void Main(){
	k=0;
	ans=-inf;
	cin>>n>>m;
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,m){
		int x;
		cin>>x;
		k=__gcd(x,k);
	}
	f(i,0,n){
		v[i%k].pb(a[i]);
	}
	f(s,0,2){
		int res=0;
		f(i,0,k){
			//eror(calc(v[i],s));
			res+=calc(v[i],s);
		}
		maxm(ans,res);
	}
	cout<<ans<<endl;
	f(i,0,k){
		v[i].clear();
	}
}
/*
1
6 2
0 6 -2 1 -4 5
1 2
*/
main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}