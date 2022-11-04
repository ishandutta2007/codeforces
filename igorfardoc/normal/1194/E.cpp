#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[maxn * 4 + 7];
vi op;

void clear_tree() {
	for(const auto& el : op) {
		t[el] = 0;
	}
	op.clear();
}

void update(int now, int l, int r, int pos, int val) {
	op.push_back(now);
	if(l == r) {
		t[now] += val;
		return;
	}
	int mid = l + (r - l) / 2;
	if(mid >= pos) {
		update(now * 2, l, mid, pos, val);
	} else {
		update(now * 2 + 1, mid + 1, r, pos, val);
	}
	t[now] = t[now * 2] + t[now * 2 + 1];
}

int get_val(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) {
		return 0;
	}
	if(l1 <= l && r <= r1) {
		return t[now];
	}
	int mid = l + (r - l) / 2;
	return get_val(now * 2, l, mid, l1, r1) + get_val(now * 2 + 1, mid + 1, r, l1, r1);
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
    vector<array<int, 3>> ver, hor;
    for(int i = 0; i < n; i++) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	if(x1 == x2) {
    		ver.push_back({x1, min(y1, y2), max(y1, y2)});
    	} else {
    		hor.push_back({min(x1, x2), max(x1, x2), y1});
    	}
    }
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    ll ans = 0;
    for(int i = 1; i < ver.size(); i++) {
    	vector<array<int, 3>> here;
    	clear_tree();
    	for(int j = 0; j < hor.size(); j++) {
    		if(ver[i][1] <= hor[j][2] && ver[i][2] >= hor[j][2] && ver[i][0] >= hor[j][0] && ver[i][0] <= hor[j][1]) {
    			here.push_back(hor[j]);
    			update(1, -5000, 5000, hor[j][2], 1);
    		}
    	}
    	for(int j = i - 1; j >= 0; --j) {
    		while(!here.empty() && here[here.size() - 1][0] > ver[j][0]) {
    			update(1, -5000, 5000, here[here.size() - 1][2], -1);
    			here.pop_back();
    		}
    		if(here.size() <= 1) {
    			break;
    		}
    		int here1 = get_val(1, -5000, 5000, ver[j][1], ver[j][2]);
    		ans += (ll)here1 * (here1 - 1) / 2;
    	}
    }
    cout << ans;

}