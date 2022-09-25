//Author: HeXun
//Date: 09-04-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
pair<int, int> pa[maxn], pb[maxn];
LL ans[maxn];
int op[maxn];
int m, n;
void add(int L, int R, LL x){
	if(L <= R){
		//cout << "add " << L << " " << R << " " << x << "\n";
		ans[L] += x;
		ans[R + 1] -= x;
	}
}
void adda(int i, int L, int R, LL x){
	if(L <= R){
		//cout << "adda " << i << " " << L << "  " << R << " " << x << "\n";
		if(i < L) add(L - i + 1, R - i + 1, x);
		else if(i > R) add(L + n - i + 1, R + n - i + 1, x);
		else {
			add(1, R - i + 1, x);
			add(L + n - i + 1, n, x);
		}
	}
}
void addb(int i, int L, int R, LL x){
	if(L <= R){
		//cout << "addb " << i << " " << L << "  " << R << " " << x << "\n";
		if(i < L) add(i + n - R + 1, i + n - L + 1, x);
		else if(i > R) add(i - R + 1, i - L + 1, x);
		else {
			add(1, i - L + 1, x);
			add(i + n - R + 1, n, x);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> m >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> pa[i].first;
		pa[i].second = i;
	}
	for(int i = 1; i <= n; i += 1){
		cin >> pb[i].first;
		pb[i].second = i;
	}
	sort(pa + 1, pa + n + 1);
	sort(pb + 1, pb + n + 1);
	// y + m - x, y <= x - m / 2
	// x - y, x - m / 2 < y <= x
	// y - x, x < y <= x + m / 2
	// x + m - y, x + m / 2 < y
	for(int i = 1, L, R; i <= n; i += 1){
		L = 1;
		R = lower_bound(pb + 1, pb + n + 1, make_pair(pa[i].first - (m + 1) / 2, (int)2e9)) - pb - 1;
		adda(i, L, R, m - pa[i].first);
		L = lower_bound(pb + 1, pb + n + 1, make_pair(pa[i].first - (m + 1) / 2, (int)2e9)) - pb;
		R = lower_bound(pb + 1, pb + n + 1, make_pair(pa[i].first, (int)2e9)) - pb- 1;
		adda(i, L, R, pa[i].first);
		L = lower_bound(pb + 1, pb + n + 1, make_pair(pa[i].first, (int)2e9)) - pb;
		R = lower_bound(pb + 1, pb + n + 1, make_pair(pa[i].first + m / 2, (int)2e9)) - pb - 1;
		adda(i, L, R, -pa[i].first);
		L = lower_bound(pb + 1, pb + n + 1, make_pair(pa[i].first + m / 2, (int)2e9)) - pb;
		R = n;
		adda(i, L, R, m + pa[i].first);
	}
	// y + m - x, y <= x - m / 2, x >= y + m / 2
	// x - y, x - m / 2 < y <= x, y <= x < y + m / 2
	// y - x, x < y <= x + m / 2, y - m / 2 <= x < y
	// x + m - y, x + m / 2 < y, x < y - m / 2
	for(int i = 1, L, R; i <= n; i += 1){
		L = lower_bound(pa + 1, pa + n + 1, make_pair(pb[i].first + (m + 1) / 2, 0)) - pa;
		R = n;
		addb(i, L, R,  pb[i].first);
		L = lower_bound(pa + 1, pa + n + 1, make_pair(pb[i].first, 0)) - pa;
		R = lower_bound(pa + 1, pa + n + 1, make_pair(pb[i].first + (m + 1) / 2, 0)) - pa - 1;
		addb(i, L, R, -pb[i].first);
		L = lower_bound(pa + 1, pa + n + 1, make_pair(pb[i].first - m / 2, 0)) - pa;
		R = lower_bound(pa + 1, pa + n + 1, make_pair(pb[i].first, 0)) - pa - 1;
		addb(i, L, R, pb[i].first);
		L = 1;
		R = lower_bound(pa + 1, pa + n + 1, make_pair(pb[i].first - m / 2, 0)) - pa - 1;
		addb(i, L, R, -pb[i].first);
	}
	LL mn = 1e18, mni = 0;
	for(int i = 1; i <= n; i += 1){
		ans[i] += ans[i - 1];
		//cout << ans[i] << " ";
		if(ans[i] < mn){
			mn = ans[i];
			mni = i;
		}
	}
	cout << mn << "\n";
	for(int i = 1; i <= n; i += 1) {
		int x = i + mni - 1;
		if(x > n) x -= n;
		op[pa[i].second] = pb[x].second;
	}
	for(int i = 1; i <= n; i += 1) cout << op[i] << " ";
	return 0;
}