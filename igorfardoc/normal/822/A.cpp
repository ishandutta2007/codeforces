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
    int a, b;
    cin >> a >> b;
    ll x = 1;
    for(int i= 0; i < min(a, b); i++) {
    	x *= (i + 1);
    }
    cout << x;
}