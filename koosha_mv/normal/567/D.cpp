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

const int N=1e6+99;

int n,k,len,m,a[N];

bool check(int x){
	vector<int> vec;
	int res=0;
	vec.pb(0);
	vec.pb(n+1);
	f(i,0,x) vec.pb(a[i]);
	sort(all(vec));
	//dbgv(vec);
	f(i,1,vec.size()){
		res+=(vec[i]-vec[i-1])/(len+1);
	}
	//eror(res);
	return res<k;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k>>len;
	cin>>m;
	f(i,0,m) cin>>a[i];
	//eror(check(20));
	//exit(0);
	int l=0,r=m+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(r==m+1) cout<<-1;
	else cout<<r;
}