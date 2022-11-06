#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<ll> t1, t2;

void update(vector<ll>& t, int now, int l, int r, int pos, int val) {
	if(l == r) {
		t[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update(t, now * 2, l, mid, pos, val);
	} else {
		update(t, now * 2 + 1, mid + 1, r, pos, val);
	}
	t[now] = t[now * 2] + t[now * 2 + 1];
}

ll get_sum(vector<ll>& t, int now, int l, int r, int l1, int r1) {
	if(l1 > r || l > r1) {
		return 0;
	}
	if(l1 <= l && r <= r1) {
		return t[now];
	}
	int mid = (l + r) / 2;
	return get_sum(t, now * 2, l, mid, l1, r1) + get_sum(t, now * 2 + 1, mid + 1, r, l1, r1);
}

int get_id(vector<ll>& t, int now, int l, int r, int need) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	if(t[now * 2] >= need) {
		return get_id(t, now * 2, l, mid, need);
	}
	return get_id(t, now * 2 + 1, mid + 1, r, need - t[now * 2]);
}

ll get_sum1(int l, int r) {
	if(l > r) {
		return 0;
	}
	ll ans = (ll)(r) * (r + 1) / 2 - (ll)(l) * (l - 1) / 2;
	return ans;
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
    vi p(n), where(n);
    for(int i = 0; i < n; i++) {
    	cin >> p[i];
    	--p[i];
    	where[p[i]] = i;
    }
    t1.assign(4 * n + 7, 0);
    t2.assign(4 * n + 7, 0);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
    	ans += get_sum(t1, 1, 0, n - 1, where[i], n - 1);
    	update(t1, 1, 0, n - 1, where[i], 1);
    	update(t2, 1, 0, n - 1, where[i], where[i]);
    	//cout << 1234 << endl;
    	int need = (i + 2) / 2;
    	int id1 = get_id(t1, 1, 0, n - 1, need);
    	ll anshere = ans;
    	int amleft = need;
    	int amright = i + 1 - amleft;
    	//cout << amleft << ' ' << amright << ' ' << id1 << endl;
    	anshere += get_sum1(id1 - amleft + 1, id1);
    	anshere -= get_sum(t2, 1, 0, n - 1, 0, id1);
    	if(id1 != n - 1) {
    		ll adding = get_sum(t2, 1, 0, n - 1, id1 + 1, n - 1);
    		anshere += adding;
    		anshere -= get_sum1(id1 + 1, id1 + amright);
    	}
    	cout << anshere << ' ';
    }
}