#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int t, n, m;
map<int, vector<int> > mp;
int x, y;
map<int, int> cnt;
vector<int> v[maxn];

inline bool cmp(int x, int y){
	return make_pair(cnt[x], x) > make_pair(cnt[y], y);
}

int main(){
	t = read();
	while(t--){
		n = read(), m = read();
		cnt.clear(), mp.clear();
		for(int i = 1;i <= n;i++) x = read(), cnt[x]++;
		while(m--){
			x = read(), y = read();
			mp[x].push_back(y), mp[y].push_back(x);
		}
		for(int i = 1;i <= n;i++) v[i].clear();
		for(auto x : cnt) v[x.second].push_back(x.first);
		vector<int> a;
		for(int i = n;i;i--) if(!v[i].empty()) a.push_back(i), sort(v[i].begin(), v[i].end(), greater<int>());
		long long ans = 0;
		for(auto x : cnt){
			vector<int> w = mp[x.first];
			sort(w.begin(), w.end(), cmp);
			int pos = 0;
			for(auto y : a){
				while(pos < w.size() && cnt[w[pos]] > y) pos++;
				for(auto z : v[y]){
					if(pos < w.size() && z == w[pos]) pos++;
					else if(x.first ^ z){
						ans = max(ans, 1ll * (x.first + z) * (x.second + y));
						break;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
}