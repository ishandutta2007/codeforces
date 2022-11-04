#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
string s;
struct Node {
	int balance;
	int maxbalance;
};

Node t[2400007];

void build(int now, int l, int r) {
	t[now].balance = 0;
	t[now].maxbalance = 0;
	if(l == r) {
		return;
	}
	int mid = (l + r) / 2;
	build(now * 2, l, mid);
	build(now * 2 + 1, mid + 1, r);
}

void update(int now, int l, int r, int pos) {
	if(l == r) {
		if(s[l] == ')') {
			t[now].balance = -1;
			t[now].maxbalance = -1;
		} else if(s[l] == '(') {
			t[now].balance = 1;
			t[now].maxbalance = 1;
		} else {
			t[now].balance = 0;
			t[now].maxbalance = 0;
		}
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(now * 2, l, mid, pos);
	} else {
		update(now * 2 + 1, mid + 1, r, pos);
	}
	t[now].balance = t[now * 2].balance + t[now * 2 + 1].balance;
	int mx = t[now * 2 + 1].maxbalance;
	mx = max(mx, t[now * 2].maxbalance + t[now * 2 + 1].balance);
	t[now].maxbalance = mx;
}
int n;
bool try1(int n1) {
	s[2 * n1] = '(';
	update(1, 0, 2 * n - 1, 2 * n1);
	if(t[1].maxbalance <= 0) {
		return true;
	}
	s[2 * n1] = ' ';
	return false;
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
    vi p(n), q(n), where(n);
    for(int i = 0; i < n; i++) {
    	cin >> p[i];
    	--p[i];
    	where[p[i]] = i;
    }
    s = "";
    for(int i = 0; i < n; i++) {
    	s += ' ';
    	s += ' ';
    }
    build(1, 0, 2 * n - 1);
    for(int i = 0; i < n; i++) {
    	cin >> q[i];
    	--q[i];
    }
    cout << n << ' ';
    int ans = n - 1;
    for(int i = 0; i < n - 1; i++) {
    	s[2 * q[i] + 1] = ')';
    	update(1, 0, 2 * n - 1, 2 * q[i] + 1);
    	while(try1(where[ans])) {
    		--ans;
    	}
    	cout << ans + 1 << ' ';
    }
}