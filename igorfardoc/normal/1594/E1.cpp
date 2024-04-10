#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int k;
    cin >> k;
    int now = 1;
    for(int i = 1; i < k; i++) {
    	int now1 = ((ll)now * now) % mod;
    	now1 = ((ll)now1 * 4) % mod;
    	now = now1;
    }
    int res = ((ll)now * now) % mod;
    res = ((ll)res * 6) % mod;
    cout << res;
}