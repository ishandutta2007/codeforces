#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long

using namespace std;

ll c, hr, hb, wr, wb;

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &c, &hr, &hb, &wr, &wb);
	if (wr < wb) swap(wb, wr), swap(hr, hb);
	if (wr < 100 && hr * wb < hb * wr) swap(wb, wr), swap(hr, hb);
	ll R = 0;
	int cnt = 0;
	for (ll i = c / wr; i >= 0; --i){
		ll cR = i * hr + hb * ((c - i * wr) / wb);
		if (cR > R) R = cR;
		++cnt;
		if (cnt > 10000000) break;
	}
	printf("%I64d\n", R);
	return 0;
}