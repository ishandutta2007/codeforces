#include<bits/stdc++.h>
#define P 271
#define mod1 1000000007
#define mod2 1791791791
#define max 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll ans = 0;
vi a;
int n;
int p1[max];
int p2[max];


void precalc() {
	p1[0] = 1;
	for(int i = 1; i < max; i++) {
		p1[i] = ((ll)p1[i - 1] * P) % mod1;
	}
	p2[0] = 1;
	for(int i = 1; i < max; i++) {
		p2[i] = ((ll)p2[i - 1] * P) % mod2;
	}
}

void rec(int l, int r) {
	if(r - l + 1 < 3) {
		return;
	}
	int mid = (l + r) / 2;
	rec(l, mid);
	rec(mid + 1, r);
	int h11 = 0;
	int h12 = 0;
	int h21 = 0;
	int h22 = 0;
	unordered_map<int, int> am, am1;
	am.reserve(4 * (r - l + 1));
	am1.reserve(4 * (r - l + 1));
	int pt;
	unordered_set<int> used;
	used.reserve(4 * (r - l + 1));
	for(pt = mid + 1; pt <= r; pt++) {
		if(am1[a[pt]] == 3) {
			--pt;
			break;
		}
		++am1[a[pt]];
		if(am1[a[pt]] == 3) {
			used.insert(a[pt]);
		}
	}
	if(pt > r) {
		pt = r;
	}
	vector<vector<pair<pair<int, int>, pair<int, int>>>> h(r - mid);

	for(int i = mid; i >= l; i--) {
		if(am[a[i]] == 1) {
			h11 = ((ll)h11 - p1[a[i]] + mod1) % mod1;
			h12 = ((ll)h12 - p2[a[i]] + mod2) % mod2;
		} else if(am[a[i]] == 2) {
			h21 = ((ll)h21 - p1[a[i]] + mod1) % mod1;
			h22 = ((ll)h22 - p2[a[i]] + mod2) % mod2;
		}
		++am[a[i]];
		if(am[a[i]] == 4) {
			break;
		}
		if(am[a[i]] == 1) {
			h11 = ((ll)h11 + p1[a[i]]) % mod1;
			h12 = ((ll)h12 + p2[a[i]]) % mod2;
		} else if(am[a[i]] == 2) {
			h21 = ((ll)h21 + p1[a[i]]) % mod1;
			h22 = ((ll)h22 + p2[a[i]]) % mod2;
		}
		if(am[a[i]] == 3) {
			while(used.find(a[i]) != used.end()) {
				--am1[a[pt]];
				if(am1[a[pt]] == 2) {
					used.erase(used.find(a[pt]));
				}
				--pt;
			}
		}
		//cout << pt - mid - 1 << ' ' << r - mid << endl;
		h[pt - mid - 1].push_back({{h11, h12}, {h21, h22}});
	}
	h11 = 0;
	h12 = 0;
	h21 = 0;
	h22 = 0;
	am.clear();
	map<pair<pair<int, int>, pair<int, int>>, int> d;
	for(int i = mid + 1; i <= r; i++) {
		if(am[a[i]] == 1) {
			h11 = ((ll)h11 - p1[a[i]] + mod1) % mod1;
			h12 = ((ll)h12 - p2[a[i]] + mod2) % mod2;
		} else if(am[a[i]] == 2) {
			h21 = ((ll)h21 - p1[a[i]] + mod1) % mod1;
			h22 = ((ll)h22 - p2[a[i]] + mod2) % mod2;
		}
		++am[a[i]];
		if(am[a[i]] == 4) {
			break;
		}
		if(am[a[i]] == 1) {
			h11 = ((ll)h11 + p1[a[i]]) % mod1;
			h12 = ((ll)h12 + p2[a[i]]) % mod2;
		} else if(am[a[i]] == 2) {
			h21 = ((ll)h21 + p1[a[i]]) % mod1;
			h22 = ((ll)h22 + p2[a[i]]) % mod2;
		}
		++d[{{h21, h22}, {h11, h12}}];
		for(const auto& p : h[i - mid - 1]) {
			ans += d[p];
		}
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
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    precalc();
    rec(0, n - 1);
    cout << ans;
}