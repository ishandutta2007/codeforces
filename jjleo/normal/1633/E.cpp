#include <bits/stdc++.h>
#define maxn 305

using namespace std;

typedef long long ll;

int n, m;
tuple<int, int, int> e[maxn];
vector<tuple<int, ll, ll> > w[maxn];

int fa[55], siz[55];

void init(){
	for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
}

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}

int p, k, a, b, c, last;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++) scanf("%d%d%d", &get<1>(e[i]), &get<2>(e[i]), &get<0>(e[i]));
	sort(e + 1, e + 1 + m);
	for(int pos = 1;pos <= m + 1;pos++){
		vector<tuple<int, int, int> > v[2];
		init();
		for(int i = pos - 1, cnt = 0;i >= 1 && cnt < n - 1;i--){
			int x = find(get<1>(e[i])), y = find(get<2>(e[i]));
			if(x == y) continue;
			cnt++, merge(x, y);
			v[0].push_back(e[i]); 
		}
		init();
		for(int i = pos, cnt = 0;i <= m && cnt < n - 1;i++){
			int x = find(get<1>(e[i])), y = find(get<2>(e[i]));
			if(x == y) continue;
			cnt++, merge(x, y);
			v[1].push_back(e[i]); 
		}
		for(int i = 0;i < v[0].size();i++) for(int j = 0;j < v[1].size();j++){
			w[pos].push_back(make_tuple(get<0>(v[0][i]) + get<0>(v[1][j]), 0, 0));
		}
		w[pos].push_back(make_tuple(1e9, 0, 0));
		sort(w[pos].begin(), w[pos].end());
		//w[pos].erase(unique(w[pos].begin(), w[pos].end()), w[pos].end());
		for(int i = 0;i < w[pos].size();i++){
			//printf("%d %d--\n", pos, get<0>(w[pos][i]));
			int l = 0, r = 0, cnt = 0, last = get<0>(w[pos][i]);
			init();
			while(cnt < n - 1){
				if(r == v[1].size() || l < v[0].size() && last <= get<0>(v[0][l]) + get<0>(v[1][r])){
					int x = find(get<1>(v[0][l])), y = find(get<2>(v[0][l]));
					l++;
					if(x == y) continue;
					cnt++, merge(x, y);
					get<1>(w[pos][i]) += -get<0>(v[0][l - 1]);
					get<2>(w[pos][i])++;
				}else{
					int x = find(get<1>(v[1][r])), y = find(get<2>(v[1][r]));
					r++;
					if(x == y) continue;
					cnt++, merge(x, y);
					get<1>(w[pos][i]) += get<0>(v[1][r - 1]);
					get<2>(w[pos][i])--;
				}
			}
		}
	}
	scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);
	ll ans = 0;
	for(int i = 1;i <= k;i++){
		if(i <= p) scanf("%d", &last);
		else last = (1ll * last * a + b) % c;
		int pos = lower_bound(e + 1, e + 1 + m, make_tuple(last, 0, 0)) - e;
		int Pos = lower_bound(w[pos].begin(), w[pos].end(), make_tuple(last * 2, -1e18, -1e18)) - w[pos].begin();
		//printf("%d %d %lld %lld %lld--\n", last, get<0>(w[pos][Pos]), get<1>(w[pos][Pos]),  get<2>(w[pos][Pos]), get<1>(w[pos][Pos]) + get<2>(w[pos][Pos]) * last);
		ans ^= get<1>(w[pos][Pos]) + get<2>(w[pos][Pos]) * last;
	}
	printf("%lld", ans);
}