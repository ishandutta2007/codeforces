#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, MXN = 100002;

ll n, q, a[100005], op[100005];

struct segtree {
    ll val[444444];
    ll ml[444444], pl[444444], as[444444];
    void init (ll P) {
        ml[P] = 1;
        pl[P] = 0;
        as[P] = -1;
    }
    void lazydown (ll SS, ll SE, ll P) {
        ll mid = (SS+SE)/2;
        ll sz[2] = {mid - SS + 1, SE - mid};
        if(as[P] != -1) {
            for(int i=2*P;i<=2*P+1;i++) {
                val[i] = sz[i - 2*P] * as[P] % mod;
                as[i] = as[P];
            }
        }
        else {
            for(int i=2*P;i<=2*P+1;i++) {
                val[i] = (ml[P] * val[i] + pl[P] * sz[i - 2*P]) % mod;
                if(as[i] != -1) {
                    as[i] = (as[i] * ml[P] + pl[P]) % mod;
                }
                else {
                    ml[i] = ml[i] * ml[P] % mod;
                    pl[i] = (pl[i] * ml[P] + pl[P]) % mod;
                }
            }
        }
        init(P);
    }
    void init (ll SS, ll SE, ll P) {
        init(P);
        if(SS == SE) {val[P] = a[SS]; return;}
        ll mid = (SS+SE)/2;
        init(SS, mid, 2*P);
        init(mid+1, SE, 2*P+1);
        val[P] = (val[2*P] + val[2*P+1]) % mod;
    }
    void Add (ll SS, ll SE, ll S, ll E, ll P, ll V) {
        if(S <= SS && SE <= E) {
            val[P] = (val[P] + V * (SE - SS + 1)) % mod;
            if(as[P] != -1) as[P] = (as[P] + V) % mod;
            else pl[P] = (pl[P] + V) % mod;
            return;
        }
        if(SE < S || E < SS) return;
        lazydown(SS, SE, P);
        ll mid = (SS+SE)/2;
        Add(SS, mid, S, E, 2*P, V);
        Add(mid+1, SE, S, E, 2*P+1, V);
        val[P] = (val[2*P] + val[2*P+1]) % mod;
    }
    void Multiple (ll SS, ll SE, ll S, ll E, ll P, ll V) {
        if(S <= SS && SE <= E) {
            val[P] = (val[P] * V) % mod;
            if(as[P] != -1) as[P] = (as[P] * V) % mod;
            else {
                ml[P] = (ml[P] * V) % mod;
                pl[P] = (pl[P] * V) % mod;
            }
            return;
        }
        if(SE < S || E < SS) return;
        lazydown(SS, SE, P);
        ll mid = (SS+SE)/2;
        Multiple(SS, mid, S, E, 2*P, V);
        Multiple(mid+1, SE, S, E, 2*P+1, V);
        val[P] = (val[2*P] + val[2*P+1]) % mod;
    }
    void Assign (ll SS, ll SE, ll S, ll E, ll P, ll V) {
        if(S <= SS && SE <= E) {
            val[P] = ((SE - SS + 1) * V) % mod;
            as[P] = V;
            return;
        }
        if(SE < S || E < SS) return;
        lazydown(SS, SE, P);
        ll mid = (SS+SE)/2;
        Assign(SS, mid, S, E, 2*P, V);
        Assign(mid+1, SE, S, E, 2*P+1, V);
        val[P] = (val[2*P] + val[2*P+1]) % mod;
    }
    ll query (ll SS, ll SE, ll S, ll E, ll P) {
        if(S <= SS && SE <= E) return val[P];
        if(SE < S || E < SS) return 0;
        lazydown(SS, SE, P);
        ll mid = (SS+SE)/2, ret = 0;
        ret = (ret + query(SS, mid, S, E, 2*P)) % mod;
        ret = (ret + query(mid+1, SE, S, E, 2*P+1)) % mod;
        return ret;
    }
} seg;

int main()
{
	scanf("%lld%lld",&n,&q);
	seg.init(0, MXN, 1);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	while(q--) {
		char typ[2];
		int T;
		scanf("%s%d",typ,&T);
		if(typ[0] == '<') T--;
		if(typ[0] == '<') {
			if(T < 0) {
				seg.Assign(0, MXN, -T, MXN, 1, 1);
			}
			else {
				seg.Multiple(0, MXN, 0, T, 1, mod-1);
				seg.Add(0, MXN, 0, T, 1, 3);
				seg.Assign(0, MXN, T+1, MXN, 1, 1);
			}
		}
		else {
			if(T < 0) {
				seg.Multiple(0, MXN, 0, -T-1, 1, mod-1);
				seg.Add(0, MXN, 0, -T-1, 1, 3);
				seg.Assign(0, MXN, -T, MXN, 1, 2);
			}
			else {
				seg.Assign(0, MXN, T+1, MXN, 1, 2);
			}
		}
	}
	for(ll i=1;i<=n;i++) {
		ll T = seg.query(0, MXN, abs(a[i]), abs(a[i]), 1);
		if(T == 0) printf("%lld ", a[i]);
		if(T == 3) printf("%lld ", -a[i]);
		if(T == 1) printf("%lld ", abs(a[i]));
		if(T == 2) printf("%lld ", -abs(a[i]));
	}
	puts("");
}