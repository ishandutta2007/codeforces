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

const int N=1e6+99;

int n,t,q,last,a[N];
ll sum;

void Main(){
	
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	f(i,1,n+1){
		cin>>a[i];
		sum+=a[i];
	}
	vector<int> vec(n);
	iota(all(vec),1);
	f(i,1,q+1){
		int t,x,val;
		cin>>t;
		if(t==1){
			cin>>x>>val;
			sum-=a[x];
			if(a[x]==0) sum-=last;
			a[x]=val;
			sum+=val;
			vec.pb(x);
		}
		else{
			cin>>val; last=val;
			for(auto x : vec) a[x]=0;
			vec.clear();
			sum=n*val;
		}
		cout<<sum<<'\n';
	}
}