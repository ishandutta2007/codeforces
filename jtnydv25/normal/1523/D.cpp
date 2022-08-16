#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif
const int N = 200005;
const int D = 15;
bitset<N> E[1 << 6];
int ok[64];
string ans;
int cnt = 0;
vector<int> ids;
int m, k;
vector<int> good;
int REQ;
void recurse(int pos, int mask, bitset<N> bs){
	if(sz(ids) + k - pos <= cnt) return;
	if(pos == k){
		cnt = sz(ids);
		string ss(m, '0');
		// trace(ss);
		for(int i : ids) ss[good[i]] = '1';
		ans = ss;
	}
	// if(pos == 0) trace(mask);
	if(mask >> pos & 1){
		if((E[good[pos]] & bs).count() >= REQ){
			ids.push_back(pos);
			recurse(pos + 1, mask & ok[pos], bs & E[good[pos]]);
			ids.pop_back();
		}
	}
	recurse(pos + 1, mask, bs);
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, p; cin >> n >> m >> p;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) if(s[j] == '1'){
			E[j][i] = 1;
		}
	}
	for(int i = 0; i < m; i++){
		if(E[i].count() >= (n + 1) / 2) good.push_back(i);
		ans += "0";
	}
	srand(time(NULL));
	random_shuffle(all(good));
	k = good.size();
	for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) ok[i] |= ((E[good[i]] & E[good[j]]).count() >= (n + 1) / 2) << j;
	REQ= (n + 1) / 2;
	bitset<N> bs;
	bs.set();
	recurse(0, (1 << k) - 1, bs);
	cout << ans << endl;
}