#include <bits/stdc++.h>

using namespace std;

#define pie  pair<int,int>
#define PB   push_back
#define L    first
#define R    second

const long double PI = 3.1415926535897932;
const int maxn = 1e5 + 100;
int n, idX[maxn];
long double val[maxn], ans, dp[maxn], seg[4 * maxn];
vector <long double> vec;

void add(long double val, int idx, int l = 0, int r = n, int id = 1){
	if(idx < l or r <= idx)
		return;
	if(r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, idx, l, mid, id * 2 + 0);
	add(val, idx, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]);
}

long double get(int R, int l = 0, int r = n, int id = 1){
	if(l >= R)
		return 0;
	if(R >= r)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(R, l, mid, id * 2 + 0), get(R, mid, r, id * 2 + 1));
}

int main()
{
	cout.precision(10);
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		long double r, h;
		cin >> r >> h;
		val[i] = r * r * h* PI;
		vec.PB(val[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for(int i = 0 ; i < n ; i++)
		idX[i] = lower_bound(vec.begin(), vec.end(), val[i]) - vec.begin();
	ans = dp[0] = val[0];
	add(dp[0], idX[0]);
	//cout << fixed << "#" << seg[1] << endl;
	//cout << fixed << dp[0] << " " << val[0] << endl;
	for(int i = 1 ; i < n ; i++){
		//cout << fixed << "#" <<  seg[1] << endl;
		dp[i] = get(idX[i]) + val[i];
		add(dp[i], idX[i]);
		ans = max(ans, dp[i]);
		//cout << fixed << dp[i] << " " << val[i] << endl;
	}
	cout << fixed << ans << endl;
	return 0;
}