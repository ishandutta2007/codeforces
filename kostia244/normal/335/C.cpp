#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
int r, n, mex[110][3][3], brd[110];
int get(int len, int l, int r) {
	if(len < 1) return 0;
	if(len == 1) {
		if(l==r) return 1;
		if(!l||!r) return 1;
		return 0;
	}
	if(mex[len][l][r]!=-1) return mex[len][l][r];
	set<int> sg;
	if(l||r)
	sg.insert(get(len-1,l,r));
	for(int l1 = (l>0); l1+(r>0) < len; l1++) {
		sg.insert(get(l1,l,1)^get(len-l1-1,1,r));
		sg.insert(get(l1,l,2)^get(len-l1-1,2,r));
	}
	mex[len][l][r]=0;
	while(sg.count(mex[len][l][r]))
		mex[len][l][r]++;
	return mex[len][l][r];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(mex, -1, sizeof mex);
	cin >> r >> n;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		brd[x]=1<<(y-1);
	}
	int ans = 0, l = 0, ln = 0;
	for(int i = 1; i <= r; i++) {
		if(brd[i]) {
			if(ln)
			ans^=get(ln, l, brd[i]);
//			,		cout << l << " " << brd[i] << " " << ln << " " << get(ln, l, brd[i])<< "\n";
			ln=0,l=brd[i];
		} else
		ln++;
//		cout << brd[i] << "\n";
	}
	ans ^= get(ln, l, 0);
	cout << (ans?"WIN":"LOSE");
}