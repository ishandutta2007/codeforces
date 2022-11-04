#include<bits/stdc++.h>
#define PI (ld)3.14159265358
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long double ld;



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
    while(t--) {
    	int n;
    	cin >> n;
    	ld one = 180 / (ld)(n);
    	ld r = (ld)1 / 2 / sin(one * PI / 360);
    	ld half = cos(one * PI / 360) * r * 2;
    	cout << fixed << setprecision(20) << half << '\n';
    }
}