#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 500005;

int n, d, m;

int main(){
	scanf("%d %d %d",&n,&d,&m);
	vector<lint> v, w;
	for(int i=0; i<n; i++){
		int y; scanf("%d",&y);
		if(y <= m) w.push_back(y);
		else v.push_back(y);
	}
	sort(all(v));
	reverse(all(v));
	sort(all(w));
	reverse(all(w));
	if(sz(v) == 0){
		cout << accumulate(all(w), 0ll) << endl;
		return 0;
	}
	for(int i=1; i<sz(w); i++) w[i] += w[i-1];
	lint ret = v[0] + (sz(w) ? w.back() : 0);
	for(int i=1; i<sz(v); i++){
		v[i] += v[i - 1];
		lint needy = 1ll * i * d;
		needy -= sz(v) - (i + 1);
		needy = max(needy, 0ll);
		if(needy <= sz(w)){
			if(needy < sz(w)) ret = max(ret, v[i] + w[sz(w) - 1 - needy]);
			else ret = max(ret, v[i]);
		}
	}
	cout << ret << endl;
}