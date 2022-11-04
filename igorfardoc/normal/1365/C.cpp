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
    cin >> n;
    vi a(n), b(n), where(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	--a[i];
    }
    for(int i = 0; i < n; i++) {
    	cin >> b[i];
    	--b[i];
    	where[b[i]] = i;
    }
    vi am(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	++am[(where[a[i]] - i + n) % n];
    	ans = max(ans, am[(where[a[i]] - i + n) % n]);
    }
    cout << ans;
}