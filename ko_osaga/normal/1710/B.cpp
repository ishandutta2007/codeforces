#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

struct event{
	int pos, a, b;
};

struct node{
	int x, p, idx;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<node> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].x >> a[i].p;
			a[i].idx = i;
		}
		sort(all(a), [&](const node &a, const node &b){
			return a.x < b.x;
		});
		vector<event> ev;
		for(int i = 0; i < n; i++){
			int L = a[i].x - a[i].p;
			int M = a[i].x;
			int R = a[i].x + a[i].p;
			ev.push_back({L, +1, -L});
			ev.push_back({M, -1, +L});
			ev.push_back({M, -1, R});
			ev.push_back({R, +1, -R});
		}
		sort(all(ev), [&](const event &a, const event &b){
			return a.pos < b.pos;
		});
		lint A = 0, B = 0;
		lint YMX = -1e18, XPY = -1e18;
		int p = 0;
		for(int i = 0; i < n; i++){
			while(p < sz(ev) && ev[p].pos <= a[i].x){
				A += ev[p].a;
				B += ev[p].b;
				p++;
			}
			lint cum = A * a[i].x + B;
			if(cum > m){
				lint X = a[i].x;
				lint Y = cum - m;
				YMX = max(YMX, Y - X);
				XPY = max(XPY, X + Y);
			}
		}
		sort(all(a), [&](const node &a, const node &b){
			return a.idx < b.idx;
		});
		for(int i = 0; i < n; i++){
			lint X = a[i].x;
			lint Y = a[i].p;
			if(YMX <= Y - X && XPY <= X + Y) cout << "1";
			else cout << "0";
		}
		cout << "\n";
	}
}