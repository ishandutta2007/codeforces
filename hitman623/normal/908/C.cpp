#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
double n,r,x[1001],y[1001];
void solve()
{
	cin>>n>>r;
	rep(i,0,n)
		cin>>x[i];
	rep(i,0,n){
		y[i]=r;
		rep(j,0,i){
			int d=4*r*r-(x[i]-x[j])*(x[i]-x[j]);
			if(d>=0)
			y[i]=max(y[i],y[j]+sqrt(d));
		}
		cout<<fixed<<setprecision(10);
		cout<<y[i]<<" ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}