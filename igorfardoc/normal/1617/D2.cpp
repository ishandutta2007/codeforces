#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi col, col1;
int n;

int q(int a, int b, int c) {
	cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
	int res;
	cin >> res;
	return res;
}

void dofor(int good, int bad, int id1) {
	col[id1] = q(good, bad, id1);
}

void print() {
	vi ans;
	for(int i = 0; i < n; i++) {
		if(col[i] == 0) {
			ans.push_back(i);
		}
	}
	cout << "! " << ans.size() << ' ';
	for(const auto& el : ans) {
		cout << el + 1 << ' ';
	}
	cout << endl;
}

pair<int, int> find_good(int a1, int a0) {
	vi indexes = {a1 * 3, a1 * 3 + 1, a1 * 3 + 2, a0 * 3, a0 * 3 + 1, a0 * 3 + 2};
	int bef = 1;
	for(int i = 1;; i++) {
		int here = q(indexes[i], indexes[i + 1], indexes[i + 2]);
		if(here != bef) {
			if(here == 1) {
				return {indexes[i + 2], indexes[i - 1]};
			} else {
				return {indexes[i - 1], indexes[i + 2]};
			}
		}
		bef = here;
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
	    col.assign(n, -1);
	    col1.assign(n / 3, -1);
	    int a0, a1;
	    for(int i = 0; i < n / 3; i++) {
	    	col1[i] = q(i * 3, i * 3 + 1, i * 3 + 2);
	    	if(col1[i] == 1) {
	    		a1 = i;
	    	} else {
	    		a0 = i;
	    	}
	    }
	    auto p = find_good(a1, a0);
	    int good = p.first;
	    int bad = p.second;
	    col[good] = 1;
	    col[bad] = 0;
	    vi indexes = {a1 * 3, a1 * 3 + 1, a1 * 3 + 2, a0 * 3, a0 * 3 + 1, a0 * 3 + 2};
	    for(auto& el : indexes) {
	    	if(col[el] != -1) {
	    		continue;
	    	}
	    	dofor(good, bad, el);
	    }
	    for(int i = 0; i < n / 3; i++) {
	    	if(col[i * 3] != -1) continue;
	    	if(col1[i] == 1) {
	    		int res = q(bad, i * 3, i * 3 + 1);
	    		if(res == 1) {
	    			col[i * 3] = 1;
	    			col[i * 3 + 1] = 1;
	    			dofor(good, bad, i * 3 + 2);
	    		} else {
	    			col[i * 3 + 2] = 1;
	    			dofor(good, bad, i * 3);
	    			col[i * 3 + 1] = 1 - col[i * 3];
	    		}
	    	} else {
	    		int res = q(good, i * 3, i * 3 + 1);
	    		if(res == 0) {
	    			col[i * 3] = 0;
	    			col[i * 3 + 1] = 0;
	    			dofor(good, bad, i * 3 + 2);
	    		} else {
	    			col[i * 3 + 2] = 0;
	    			dofor(good, bad, i * 3);
	    			col[i * 3 + 1] = 1 - col[i * 3];
	    		}
	    	}
	    }
	    print();
	}
}