#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 1005;
const ll mod = 1e9+7;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q) {
        q --;
        int h, m;
        cin >> h >> m;
        m = h*60+m;
        cout << 24*60-m << E;
	}
    return 0;
}