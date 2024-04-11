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

int n=200,t,last,a[N];

int ask(int x){
	vector<pair<int,int>> vec;
	f(i,1,n+1){
		if(i%x) continue ;
		f(j,1,n+1) vec.pb({i,j});
	}
	cout<<"? "<<vec.size()<<endl;
	for(auto p : vec) cout<<p.F<<" "<<p.S<<" ";
	cout<<endl;
	int res;
	cin>>res;
	return res;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int area=ask(1);
	int l=0,r=8;
	while(l+1<r){
		int mid=(l+r)>>1,res=ask(1<<mid);
		if((res<<mid)==area) l=mid;
		else r=mid,last=res;
	}
	int len;
	if(l==7){
		len=128;
	}
	else{
		len=abs((area-last*(1<<r))/(1<<l));
	}
	cout<<"! "<<2*(len+area/len)-4<<endl;
	
}