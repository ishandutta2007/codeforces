#include<bits/stdc++.h>
#define prev prev1
#define right right1
#define left left1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, q;
vi mass;
vi am;
vector<pair<int, int>> prev;
vector<ll> pref;
ll ans = 0;
vi left, right;

ll get_sum(int l, int r) {
	if(l > r) {
		return 0;
	}
	return pref[r + 1] - pref[l];
}

void join(int i) {
	//cout << i << endl;
	//cout << 1 << endl;
	ans -= get_sum(i - am[i] + 1, i);
	int r1 = right[i + 1];
	int l1 = left[i];
	ans -= get_sum(r1 - am[r1] + 1, r1);
	right[l1] = r1;
	left[r1] = l1;
	am[l1] = am[i] + am[r1];
	am[r1] = am[l1];
	//cout << am[r1] << endl;
	ans += get_sum(r1 - am[r1] + 1, r1);
	//cout << 2 << endl;
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
    cin >> n >> m >> q;
    prev.resize(n + m);
    for(int i = 0; i < n; i++) {
    	cin >> prev[i].first;
    	ans += prev[i].first;
    	prev[i].second = 1;
    }
    for(int i = 0; i < m; i++) {
    	cin >> prev[i + n].first;
    	prev[i + n].second = 0;
    }
    sort(prev.begin(), prev.end());
    mass.resize(n + m);
    am.resize(n + m);
    left.resize(n + m);
    right.resize(n + m);
    for(int i = 0; i < n + m; i++) {
    	mass[i] = prev[i].first;
    	am[i] = prev[i].second;
    	left[i] = i;
    	right[i] = i;
    }
    pref.assign(n + m + 1, 0);
    for(int i = 1; i <= n + m; i++) {
    	pref[i] = pref[i - 1] + mass[i - 1];
    }
    vector<pair<int, int>> deltas;
    for(int i = 0; i < n + m - 1; i++) {
    	deltas.push_back({mass[i + 1] - mass[i], i});
    }
    sort(deltas.begin(), deltas.end());
    vector<pair<int, int>> qu(q);
    for(int i = 0; i < q; i++) {
    	cin >> qu[i].first;
    	qu[i].second = i;
    }
    sort(qu.begin(), qu.end());
    vector<ll> res(q);
    int pt = 0;
    for(int i = 0; i < q; i++) {
    	while(pt < deltas.size() && deltas[pt].first <= qu[i].first) {
    		join(deltas[pt].second);
    		++pt;
    	}
    	res[qu[i].second] = ans;
    }
    for(const auto& el : res) {
    	cout << el << '\n';
    }
}