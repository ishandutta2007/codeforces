#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

vector<int> t;
int n;

void upd(int pos, int val) {
	for (pos += n; pos; pos >>= 1) {
		t[pos] = max(t[pos], val);
	}
}

int get(int l, int r) {
	int ans = 0;
	for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if (l & 1) {
			ans = max(ans, t[l]);
		}
		if (!(r & 1)) {
			ans = max(ans, t[r]);
		}
	}
	return ans;
}

struct datum {
	int pos;
	int h;
	int id;
	bool operator<(const datum& other) const {
		return pos < other.pos;
	}
};

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;

    t.resize(2 * n);

    vector<datum> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i].pos >> a[i].h;
    	a[i].id = i;
    }
    sort(all(a));

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
    	upd(i, i);
    	datum tmp = {a[i].pos + a[i].h - 1, 0, 0};
    	int j = upper_bound(all(a), tmp) - a.begin();
    	--j;
    	while (true) {
    		int k = get(i, j);
    		if (k == j) {
    			break;
    		}
    		j = k;
    	}
    	upd(i, j);
    	ans[a[i].id] = j - i + 1;
    }

    for (int i = 0; i < n; ++i) {
    	cout << ans[i] << " ";
    }
    cout << "\n";

}