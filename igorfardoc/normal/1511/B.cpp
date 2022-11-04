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
    int t;
    cin >> t;
    vi p(10);
    p[0] = 1;
    for(int i = 1; i <= 9; i++) {
    	p[i] = p[i - 1] * 10;
    }
    while(t--) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	cout << p[c - 1] * (p[a - c] + 1) << ' ' << p[c - 1] * p[b - c] << '\n';
    }
}