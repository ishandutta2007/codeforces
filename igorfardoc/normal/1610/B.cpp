#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi a;
int n;


bool check(int x) {
	vi b;
	for(int i = 0; i < n; i++) {
		if(a[i] != x) {
			b.push_back(a[i]);
		}
	}
	for(int i = 0; i < (int)b.size() / 2; i++) {
		if(b[i] != b[b.size() - 1 - i]) {
			return false;
		}
	}
	return true;
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
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	if(check(-1)) {
    		cout << "YES\n";
    		continue;
    	}
    	int l = 0;
    	int r = n - 1;
    	while(a[l] == a[r]) {
    		++l;
    		--r;
    	}
    	if(check(a[l]) || check(a[r])) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}