#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[2000007];
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
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(now * 2, l, mid, pos, val);
	} else {
		update(now * 2 + 1, mid + 1, r, pos, val);
	}
	t[now] = t[now * 2] + t[now * 2 + 1];
}

int get_sum(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) {
		return 0;
	}
	if(l1 <= l && r <= r1) {
		return t[now];
	}
	int mid = (l + r) / 2;
	return get_sum(now * 2, l, mid, l1, r1) + get_sum(now * 2 + 1, mid + 1, r, l1, r1);
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
    	int n;
    	cin >> n;
    	vi a(n);
    	set<int> was;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		--a[i];
    	}
    	bool ok = false;
    	for(int i = 0; i < n; i++) {
    		if(was.find(a[i]) != was.end()) {
    			ok = true;
    			break;
    		}
    		was.insert(a[i]);
    	}
    	if(ok) {
    		cout << "YES\n";
    		continue;
    	}
    	clear_tree();
    	ll ans = 0;
    	for(int i = 0; i < n; i++) {
    		ans += get_sum(1, 0, n, a[i] + 1, n);
    		update(1, 0, n, a[i], 1);
    	}
    	if(ans % 2 == 0) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}