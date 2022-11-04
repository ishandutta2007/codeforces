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
    while(t--) {
    	int n, l, r, s;
    	cin >> n >> l >> r >> s;
    	--l;
    	--r;
    	int len = r - l + 1;
    	int min1 = len * (len + 1) / 2;
    	int max1 = n * (n + 1) / 2 - (n - len) * (n - len + 1) / 2;
    	if(min1 > s || max1 < s) {
    		cout << "-1\n";
    		continue;
    	}
    	s -= min1;
    	vi res(n);
    	set<int> s1;
    	for(int i = 1; i <= n; i++) {
    		s1.insert(i);
    	}
    	for(int i = 0; i < len; i++) {
    		int can = n - i - (len - i);
    		if(can < s) {
    			s -= can;
    			s1.erase(s1.find(n - i));
    			res[i + l] = n - i;
    		} else {
    			s1.erase(s1.find(len - i + s));
    			res[i + l] = len - i + s;
    			s = 0;
    		}
    	}
    	//cout << 123 << endl;
    	for(int i = 0; i < n; i++) {
    		if(i >= l && i <= r) {
    			continue;
    		}
    		res[i] = *(s1.begin());
    		s1.erase(s1.begin());
    	}
    	for(int i = 0; i < n; i++) {
    		cout << res[i] << ' ';
    	}
    	cout << '\n';
    }
}