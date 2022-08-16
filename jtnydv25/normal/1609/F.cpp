#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif
const int N = 1 << 20;
int mx[N], mn[N], id[N], bits[N], bits2[N];
int cnt[64];

ll ans = 0;

inline void get_mxmn(int L, int R){
	mx[L] = mn[L] = id[L];
	for(int i = L + 1; i <= R; i++){
		mx[i] = max(mx[i - 1], id[i]);
		mn[i] = min(mn[i - 1], id[i]);
	}
}

void eval(int L1, int R1, int L2, int R2){
	memset(cnt, 0, sizeof cnt);
	get_mxmn(L2, R2);
	int ptr_mx = L2, ptr_mn = L2;
	int ptr3 = L2 - 1;
	int P = -1, Q = N + 1;
	int u = -1, v = -1;
	for(int i = L1; i <= R1; i++){
		if(id[i] > P){
			u = bits[i];
			P = id[i];
		}
		if(id[i] < Q){
			v = bits[i];
			Q = id[i];
		}
		while(ptr_mn <= R2 && mn[ptr_mn] > Q){
			if(ptr_mn < ptr_mx) cnt[bits2[mn[ptr_mn]]]--;
			ptr_mn++;
		}
		while(ptr_mx <= R2 && mx[ptr_mx] < P){
			if(ptr_mx >= ptr_mn) cnt[bits2[mn[ptr_mx]]]++;
			ptr_mx++;
		}
		if(u == v) ans += min(ptr_mn, ptr_mx) - L2;
		ans += cnt[u];
	}

}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll &x: a){
		cin >> x;
	}
	
	vector<int> perm(n);
	iota(all(perm), 0);
	sort(all(perm), [&](int x, int y){return a[x] < a[y];});

	for(int i = 0; i < n; i++){
		id[perm[i]] = i;
		bits[i] = __builtin_popcountll(a[i]);
		bits2[i] = __builtin_popcountll(a[perm[i]]);
	}
	
	function<void(int, int)> recurse = [&](int L, int R){
		if(L == R){
			ans++;
			return;
		}
		int M = (L + R) >> 1;
		reverse(id + L, id + M + 1);
		reverse(bits + L, bits + M + 1);
		int old_ans = ans;
		eval(L, M, M + 1, R);
		eval(M + 1, R, L, M);
		reverse(id + L, id + M + 1);
		reverse(bits + L, bits + M + 1);
		recurse(L, M);
		recurse(M + 1, R);
	};
	recurse(0, n - 1);
	cout << ans << endl;
}