#include<bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<ll> tree;
vector<ll> lp;

void add(int now, int l, int r, int l1, int r1, int val) {
	if(l > r1 || l1 > r) {
		return;
	}
	if(l1 <= l && r <= r1) {
		lp[now] += val;
		tree[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	add(now * 2, l, mid, l1, r1, val);
	add(now * 2 + 1, mid + 1, r, l1, r1, val);
	tree[now] = min(tree[now * 2], tree[now * 2 + 1]) + lp[now];
}

ll get_min(int now, int l, int r, int l1, int r1) {
	if(l > r1 || l1 > r) {
		return INF;
	}
	if(l1 <= l && r <= r1) {
		return tree[now];
	}
	int mid = (l + r) / 2;
	return min(get_min(now * 2, l, mid, l1, r1), get_min(now * 2 + 1, mid + 1, r, l1, r1)) + lp[now];
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
    vi p(n);
    vi a(n);
    tree.assign(4 * n + 7, 0);
    lp.assign(4 * n + 7, 0);
    vi where(n);
    for(int i = 0; i < n; i++) {
    	cin >> p[i];
    	--p[i];
    	where[p[i]] = i;
    }
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    //cout << 1234 << endl;
    for(int i = 1; i < n; i++) {
    	add(1, 0, n - 1, where[i], n - 1, a[where[i]]);
    }
    //cout << 1234 << endl;
    if(where[0] != 0) {
    	add(1, 0, n - 1, 0, where[0] - 1, a[where[0]]);
    }
    int ans = min(a[0], a[n - 1]);
    ans = min((ll)ans, get_min(1, 0, n - 1, 0, n - 2));
    //cout << 123 << endl;
    for(int i = 1; i < n; i++) {
    	add(1, 0, n - 1, where[i], n - 1, -a[where[i]]);
    	if(where[i] != 0) {
    		add(1, 0, n - 1, 0, where[i] - 1, a[where[i]]);
    	}
    	ans = min((ll)ans, get_min(1, 0, n - 1, 0, n - 2));
    }
    cout << ans;
}