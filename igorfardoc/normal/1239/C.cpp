#include<bits/stdc++.h>
#define INF 1000000000000001ll
#define MAX 100000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll t[MAX * 4 + 7];
ll lp[MAX * 4 + 7];


void update(int now, int l, int r, int l1, int r1, ll val) {
	if(l1 > r || l > r1) {
		return;
	}
	if(l1 <= l && r <= r1) {
		lp[now] += val;
		t[now] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(now * 2, l, mid, l1, r1, val);
	update(now * 2 + 1, mid + 1, r, l1, r1, val);
	t[now] = min(t[now * 2], t[now * 2 + 1]) + lp[now];
}

int get_min(int now, int l, int r) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	if(t[now * 2] <= t[now * 2 + 1]) {
		return get_min(now * 2, l, mid);
	}
	return get_min(now * 2 + 1, mid + 1, r);
}

int get_min1(int now, int l, int r, ll par, ll lp1=0) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	lp1 += lp[now];
	if(t[now * 2] + lp1 <= par) {
		return get_min1(now * 2, l, mid, par, lp1);
	}
	return get_min1(now * 2 + 1, mid + 1, r, par, lp1);
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
    int n, p;
    cin >> n >> p;
    vector<ll> t(n);
    for(int i = 0; i < n; i++) {
    	cin >> t[i];
    }
    queue<int> q;
    ll time = 0;
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
    	update(1, 0, n - 1, i, i, t[i]);
    }
    set<int> all;
    int am = 0;
    while(am < n) {
    	if(!q.empty()) {
    		int v = q.front();
    		ans[v] = p + time;
    		++am;
    		while(true) {
    			int min1 = *(all.begin());
    			update(1, 0, n - 1, min1, n - 1, INF);
    			int id1 = get_min(1, 0, n - 1);
    			update(1, 0, n - 1, min1, n - 1, -INF);
    			if(t[id1] < p + time && ans[id1] == -1 && id1 < min1 && t[id1] != INF) {
    				update(1, 0, n - 1, id1, id1, INF - t[id1]);
    				t[id1] = INF;
    				q.push(id1);
    				all.insert(id1);
    			} else {
    				break;
    			}
    		}
    		all.erase(all.find(v));
    		q.pop();
    		time += p;
    	}
		int min1 = n;
    	if(!all.empty()) {
    		min1 = *(all.begin());
    		update(1, 0, n - 1, min1, n - 1, INF);
    	}
		int id1 = get_min1(1, 0, n - 1, time);
		if(!all.empty()) {
    		update(1, 0, n - 1, min1, n - 1, -INF);
    	}
		if(ans[id1] == -1 && id1 < min1 && t[id1] <= time) {
			update(1, 0, n - 1, id1, id1, INF - t[id1]);
			if(q.empty()) {
				time = max(time, (ll)t[id1]);
			}
			t[id1] = INF;
			q.push(id1);
			all.insert(id1);
		}
    	if(q.empty()) {
    		time = t[get_min(1, 0, n - 1)];
    	}
    }
    for(ll val : ans) {
    	cout << val << ' ';
    }

}