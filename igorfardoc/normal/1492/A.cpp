#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
    while(t--)
    {
    	ll p, a, b, c;
    	cin >> p >> a >> b >> c;
    	cout << min((a - p % a) % a, min((b - p % b) % b, (c - p % c) % c)) << '\n';
    }
}