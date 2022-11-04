#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int tree[2500007];
int lp[2500007];
ll ans;

vector<int> merge_sort(vector<int>& a, int l, int r) {
	if(l == r) {
		return {a[l]};
	}
	int mid = (l + r) / 2;
	auto fir = merge_sort(a, l, mid);
	auto sec = merge_sort(a, mid + 1, r);
	int now1 = 0;
	int now2 = 0;
	vi res(r - l + 1);
	for(int i = 0; i < r - l + 1; i++) {
		if(now1 == fir.size()) {
			res[i] = sec[now2++];
			continue;
		}
		if(now2 == sec.size()) {
			res[i] = fir[now1++];
			continue;
		}
		if(fir[now1] <= sec[now2]) {
			res[i] = fir[now1++];
		} else {
			res[i] = sec[now2++];
		}
	}
	now2 = 0;
	for(int i = 0; i < fir.size(); i++) {
		while(now2 < sec.size() && sec[now2] < fir[i]) {
			++now2;
		}
		ans += now2;
	}
	return res;
}

void build_tree(int now, int l, int r, vector<int>& mass) {
	if(l == r) {
		tree[now] = mass[l];
		lp[now] = mass[l];
		return;
	}
	int mid = (l + r) / 2;
	build_tree(now * 2, l, mid, mass);
	build_tree(now * 2 + 1, mid + 1, r, mass);
	tree[now] = 0;
	lp[now] = min(lp[now * 2], lp[now * 2 + 1]);
}
int get_min(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) {
		return INF;
	}
	if(l1 <= l && r <= r1) {
		return lp[now];
	}
	int mid = (l + r) / 2;
	return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1)) + tree[now];
}
void update(int now, int l, int r, int l1, int r1, int val) {
	if(l > r1 || l1 > r) {
		return;
	}
	if(l1 <= l && r <= r1) {
		tree[now] += val;
		lp[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(now * 2, l, mid, l1, r1, val);
	update(now * 2 + 1, mid + 1, r, l1, r1, val);
	lp[now] = min(lp[now * 2], lp[now * 2 + 1]) + tree[now];
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
    	int n, m;
    	cin >> n >> m;
    	vi a(n), b(m);
    	vi all;
 		all.reserve(n + m);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		all.push_back(a[i]);
    	}
    	for(int i = 0; i < m; i++) {
    		cin >> b[i];
    		all.push_back(b[i]);
    	}
    	sort(all.begin(), all.end());
    	sort(b.begin(), b.end());
    	int now = 0;
    	unordered_map<int, int> d;
    	d.reserve(n + m);
    	for(int el : all) {
    		if(d.find(el) == d.end()) {
    			d[el] = now++;
    		}
    	}
    	//cout << "A: ";
    	for(int i = 0; i < n; i++) {
    		a[i] = d[a[i]];
    		//cout << a[i] << ' ';
    	}
    	//cout << endl;
    	//cout << "B: ";
    	for(int i = 0; i < m; i++) {
    		b[i] = d[b[i]];
    		//cout << b[i] << ' ';
    	}
    	//cout << endl;
    	ans = 0;
    	merge_sort(a, 0, n - 1);
    	//cout << ans << endl;
    	vector<vector<int>> pos(now);
    	for(int i = 0; i < n; i++) {
    		pos[a[i]].push_back(i);
    	}
    	vi mass(n + 1, 0);
    	int now1 = 0;
    	for(int i = 0; i < n; i++) {
    		if(a[i] > b[0]) {
    			++now1;
    		}
    		mass[i + 1] += now1;
    	}
    	now1 = 0;
    	for(int i = n - 1; i >= 0; i--) {
    		if(a[i] < b[0]) {
    			++now1;
    		}
    		mass[i] += now1;
    	}
    	//for(int i = 0; i <= n; i++) {
    	//	cout << mass[i] << endl;
    	//}
    	build_tree(1, 0, n, mass);
    	for(int i = 0; i < m; i++) {
    		ans += get_min(1, 0, n, 0, n);
    		if(i == m - 1) {
    			break;
    		}
    		if(b[i] == b[i + 1]) {
    			continue;
    		}
    		for(int j = b[i]; j <= b[i + 1]; j++) {
    			for(int k = 0; k < pos[j].size(); k++) {
    				if(j != b[i]) {
    					update(1, 0, n, pos[j][k] + 1, n, -1);
    				}
    				if(j != b[i + 1]) {
    					update(1, 0, n, 0, pos[j][k], 1);
    				}
    			}
    		}
		}
		cout << ans << '\n';
	}
}