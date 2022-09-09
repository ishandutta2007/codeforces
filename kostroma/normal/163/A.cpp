#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

#define int li
int mod=1000000007;
string s, t;
int dp[5005][5005];

void solve()
{
	cin>>s>>t;
	int ans=0;
	for (int i=0; i<t.length(); i++)
	{
		for (int j=0; j<s.length(); j++)
			if (t[i]==s[j])
				dp[i][j+1]++;
		if (i+1<t.length())
			for (int en=1; en<=s.length(); en++)
			{
				//cout<<i<<' '<<en<<' '<<dp[i][en]<<endl;
				dp[i+1][en]+=dp[i][en];
				dp[i+1][en]%=mod;
				if (en<s.length() && s[en]==t[i+1])
					dp[i+1][en+1]+=dp[i][en], dp[i+1][en+1]%=mod;
			}
	}
	for (int i=0; i<=s.length(); i++)
		ans+=dp[t.length()-1][i], ans%=mod;
	cout<<ans;

}