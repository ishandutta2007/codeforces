#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

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
// f[0]=1
// f[1]=x
// f[i]=x*f[i-1]+f[i-2]
int n,pol[200][200];
void solve()
{
	cin>>n;
	pol[0][0]=1;
	pol[1][1]=1;
	rep(i,2,n+1){
		rep(j,0,200)
			pol[i][j+1]=(pol[i][j+1]+pol[i-1][j])%2;
		rep(j,0,200)
			pol[i][j]=(pol[i][j]+pol[i-2][j])%2;
	}
	cout<<n<<endl;
	rep(i,0,n+1)
		cout<<pol[n][i]<<" ";
	cout<<endl<<n-1<<endl;
	rep(i,0,n)
		cout<<pol[n-1][i]<<" ";

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