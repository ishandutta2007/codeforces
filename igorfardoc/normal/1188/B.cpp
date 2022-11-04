#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k, p;
int calc(int a) {
	int res = (ll)a * a % p * a % p * a % p;
	res = (res - (ll)a * k % p + p) % p;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> p >> k;
    map<int, int> am;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	int val = calc(a);
    	ans += am[val]++;
    }
    cout << ans;
}