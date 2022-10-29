#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define	int			long long
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
int expo(int base, int exponent, int mod) {								//return base^exponent modulo modulus
    int ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
unordered_map<int,int> dp;
int sol(int num)
{
	if(dp.count(num)) return dp[num];
	int ans=expo(2,num-1,hell)-1;
	for(int j=2;j*j<=num;++j)
	if(num%j==0)
	{
		ans=(ans-sol(j)+hell)%hell;
		if(j*j!=num)
			ans=(ans-sol(num/j)+hell)%hell;
	}
	return dp[num]=ans;
}
void solve()
{
	int x,y,d;
	cin>>x>>y;
	if(y%x!=0){
		cout<<0;
		return;
	}
	y/=x;
	if(y==1) 
		{
			cout<<1;
			return;
		}
	cout<<sol(y);
}

signed main()
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