#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int rec(vi a, int last) {
	if(a.size() == 2) {
		return 2;
	}
	vi a1, a2;
	for(int i = 0; i < a.size(); i++) {
		if((a[i] >> last) & 1) {
			a1.push_back(a[i]);
		} else {
			a2.push_back(a[i]);
		}
	}
	for(int i = 0; i < a1.size(); i++) {
		a1[i] ^= 1 << last;
	}
	if(a1.size() <= 1) {
		return rec(a2, last - 1) + a1.size();
	}
	if(a2.size() <= 1) {
		return rec(a1, last - 1) + a2.size();
	}
	return max(rec(a1, last - 1), rec(a2, last - 1)) + 1;
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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    cout << n - rec(a, 29);
}