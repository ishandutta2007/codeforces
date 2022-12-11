#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 4e5 + 10;

struct Node {
	int l, r, id;
	bool operator < (const Node &b) const {
		return r < b.r || (r == b.r && l > b.l);
	}
} a[N];
int n, k, p, vis[N];
bool cmp(Node a, Node b) {
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}
priority_queue<Node> pq;
int bit[N];
void ins(int x, int y) {
	for(; x <= p; x += x & (-x))
		bit[x] += y;
}
int qry(int x) {
	int ans = 0;
	for(; x >= 1; x &= x - 1)
		ans += bit[x];
	return ans;
}
int main() {
	ucin();
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].l >> a[i].r;
		a[i].id = i; p = max(p, a[i].r);
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i ++) {
		if(qry(p) - qry(a[i].l - 1) < k) {
			vis[a[i].id] = 1; pq.push(a[i]); ins(a[i].r, 1);
		} else {
			Node u = pq.top();
			if(u.r >= a[i].r) {
				pq.pop(); pq.push(a[i]); 
				vis[u.id] = 0; vis[a[i].id] = 1;
				ins(u.r, -1); ins(a[i].r, 1);
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) if(!vis[i]) cnt ++;
	cout << cnt << endl;
	for(int i = 1; i <= n; i ++) if(!vis[i])
		cout << i << ' ';
	return 0;
}