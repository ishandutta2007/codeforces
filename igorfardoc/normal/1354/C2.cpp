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
    	int id1 = 0;
    	ld min1 = 45;
    	ld one = 180 / (ld)(n);
    	for(int i = 1; i < n - 1; i++) {
    		ld here = i * one;
    		if(abs(here - 45) < min1) {
    			min1 = abs(here - 45);
    			id1 = i;
    		}
    	}
    	ld angle = id1 * one * PI / 180;
    	ld r = (ld)1 / 2 / sin(one * PI / 360);
    	ld sum = r * (sin(angle) + cos(angle));
    	cout << fixed << setprecision(20) << sum * sqrt((ld)2) << '\n';
    }
}