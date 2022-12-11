#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int countOnes(const string& s) {
	int ans = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == '1') {
			++ans;
		}
	}
	return ans;
}

struct history {
	vector<pii> vct;
	string result;
};

void rev(string& s, int l, int r) {
	for (int i = l, j = r; i < j; ++i, --j) {
		swap(s[i], s[j]);
	}
}

int find_kth(string& s, int start, int k) {
	while (true) {
		if (s[start] == '1') {
			--k;
			if (k == 0) {
				return start;
			}
		}
		++start;
	}
}

history normalize(string s, int ones, int k) {
	if (ones == k) {
		int lst;
		history ans;
		for (int i = 0; i < sz(s); ++i) {
			if (s[i] == '1') {
				lst = i;
			}
		}
		ans.vct.pb({0, lst});
		rev(s, 0, lst);
		ans.result = s;
		return ans;
	}
	int ptr = find_kth(s, 0, k);
	history ans;
	for (int i = 0; i < ones - k; ++i) {
		ans.vct.pb({i, ptr});
		rev(s, i, ptr);
		if (i != ones - k - 1) {
			ptr = find_kth(s, ptr + 1, 1);
		}
	}
	//cout << "! " << s << endl;
	for (int i = 0; i < k; ++i) {
		int l = find_kth(s, 0, ones - k);
		int r = find_kth(s, 0, ones);
		//cout << l << " " << r << endl;
		if (i % 2 == 0) {
			ans.vct.pb({l + 1, r});
			rev(s, l + 1, r);
		} else {
			ans.vct.pb({l, r - 1});
			rev(s, l, r - 1);
		}
	}
	//cout << "!!" << s << endl;
	int l = ones - k - 1;
	int r = find_kth(s, 0, ones - 1);
	ans.vct.pb({l, r});
	rev(s, l, r);
	//cout << l << " " << r << endl;
	//cout << s << endl;
	ans.result = s;
	return ans;
}

void finish(history& x, int k) {
	int u, v;
	int cnt = 0;

	for (int i = sz(x.result) - 1; i >= 0; --i) {
		if (x.result[i] == '1') {
			++cnt;
			if (cnt == 1) {
				v = i;
			}
			if (cnt == k + 1) {
				u = i;
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		if (i % 2 == 0) {
			x.vct.pb({u + 1, v});
			rev(x.result, u + 1, v);
		} else {
			x.vct.pb({u, v - 1});
			rev(x.result, u, v - 1);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n, k;
    	cin >> n >> k;
    	string a, b;
    	cin >> a >> b;
    	int ones = countOnes(a);
    	if (ones != countOnes(b)) {
    		cout << "-1\n";
    		continue;
    	}
    	if (ones < k || k == 0) {
    		if (a == b) {
    			cout << "0\n";
    		} else {
    			cout << "-1\n";
    		}
    		continue;
    	}

    	if (a == b) {
    		cout << "0\n";
    		continue;
    	}

    	history x = normalize(a, ones, k);
    	history y = normalize(b, ones, k);
    	//cout << "PROCESSED" << endl;

    	if (ones == k) {
    		if (x.result != y.result) {
    			int lst = 0;
    			for (int i = 0; i < n; ++i) {
    				if (x.result[i] == '1') {
    					lst = i;
    				}
    			}
    			x.vct.pb({0, lst});
    			rev(x.result, 0, lst);
    		}
    	} else if (x.result != y.result && k % 2 == 1) {
    		finish(x, k);
    		finish(y, k);
    	}
    	if (x.result != y.result) {
    		cout << "-1\n";
    	} else {
    		cout << sz(x.vct) + sz(y.vct) << "\n";
    		for (int i = 0; i < sz(x.vct); ++i) {
    			cout << x.vct[i].first + 1 << " " << x.vct[i].second + 1 << "\n";
    		}
    		for (int i = sz(y.vct) - 1; i >= 0; --i) {
    			cout << y.vct[i].first + 1 << " " << y.vct[i].second + 1 << "\n";
    		}
    	}
    }

}