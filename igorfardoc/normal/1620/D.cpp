#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi a;
int n;
int ans;

bool can(int am3, int am2, int am1, int a) {
	for(int i = 0; i <= am1; i++) {
		for(int j = 0; j <= am2; j++) {
			int a1 = a - i - j * 2;
			if(a1 < 0) continue;
			if(a1 % 3 == 0 && a1 / 3 <= am3) {
				return true;
			}
		}
	}
	return false;
}

bool can(int am3, int am2, int am1) {
	for(int i = 0; i < n; i++) {
		if(!can(am3, am2, am1, a[i])) {
			return false;
		}
	}
	return true;
}
void check(int am3, int am2, int am1) {
	if(am3 < 0 || am2 < 0 || am1 < 0) return;
	if(can(am3, am2, am1)) {
		ans = min(ans, am3 + am2 + am1);
	}
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
    int t;
    cin >> t;
    while(t--) {
    	cin >> n;
    	a.resize(n);
    	int mx = 0;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		mx = max(mx, a[i]);
    	}
    	ans = 1000000000;
    	int start3 = mx / 3 - 5;
    	int end3 = mx / 3 + 5;
    	for(int am3 = start3; am3 <= end3; am3++) {
    		for(int am2 = 0; am2 <= 5; am2++) {
    			for(int am1 = 0; am1 <= 5; am1++) {
    				check(am3, am2, am1);
    			}
    		}
    	}
    	cout << ans << '\n';
    }

}