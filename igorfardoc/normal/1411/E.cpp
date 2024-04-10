#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    ll k;
    cin >> n >> k;
    vi am(61);
    string s;
    cin >> s;
    k -= (1 << (s[n - 1] - 'a'));
    k += (1 << (s[n - 2] - 'a'));
    vi a(n - 2);
    for(int i = 0; i < n - 2; i++) {
    	a[i] = 1 << ((int)s[i] - 'a');
    }
    sort(a.begin(), a.end());
    k = abs(k);
    for(int i = n - 3; i >= 0; i--) {
    	k = abs(k - a[i]);
    }
    if(k == 0) {
    	cout << "Yes\n";
    } else {
    	cout << "No\n";
    }
}