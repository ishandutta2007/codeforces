#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return _gcd(b, a % b);
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
    set<int> s;
    int now = 1;
    for(int i = 1; i <= n; i++) {
    	if(_gcd(i, n) == 1) {
    		s.insert(i);
    		now = ((ll)now * i) % n;
    	}
    }
    if(now != 1) {
    	s.erase(s.find(now));

    }
    cout << s.size() << '\n';
    for(auto el : s) {
    	cout << el << ' ';
    }
}