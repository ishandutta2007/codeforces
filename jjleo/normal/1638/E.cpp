#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

ll a[maxn];

void add(int x, ll y){
	for(;x < maxn;x += x & -x) a[x] += y;
}

ll query(int x){
	ll sum = 0;
	for(;x;x -= x & -x) sum += a[x];
	return sum;
}

int n, q;
ll f[maxn];
typedef tuple<int, int, int> t;
set<t> st; 
char s[maxn];

inline void insert(int l, int r, int c){
	if(l > r) return;
	add(l, -f[c]), add(r + 1, f[c]);
	st.insert(make_tuple(l, r, c));
}

int main(){
	scanf("%d%d", &n, &q);
	st.insert(make_tuple(1, n, 1));
	while(q--){
		scanf("%s", s);
		if(s[0] == 'C'){
			int l, r, c;
			scanf("%d%d%d", &l, &r, &c);
			int al = l;
			while(l <= r){
				set<t>::iterator it = st.lower_bound(make_tuple(l, 0, 0));
				if(it == st.end() || get<0>(*it) > l) --it;
				t x = *it;
				st.erase(it);
				add(get<0>(x), f[get<2>(x)]), add(get<1>(x) + 1, -f[get<2>(x)]);
				int L = max(l, get<0>(x)), R = min(r, get<1>(x));
				insert(get<0>(x), L - 1, get<2>(x));
				insert(R + 1, get<1>(x), get<2>(x));
				l = R + 1;
			}
			insert(al, r, c);
		}else if(s[0] == 'A'){
			int x, y;
			scanf("%d%d", &x, &y);
			f[x] += y;
		}else{
			int l;
			scanf("%d", &l);
			set<t>::iterator it = st.lower_bound(make_tuple(l, 0, 0));
			if(it == st.end() || get<0>(*it) > l) --it;
			t x = *it;
			printf("%lld\n", query(l) + f[get<2>(x)]);
		}
	}
}