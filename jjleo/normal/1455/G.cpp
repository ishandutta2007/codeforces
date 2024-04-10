#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m;
map<int, ll> mp[maxn];
multiset<ll> st[maxn];
ll val[maxn];
int id[maxn];
int cnt;
char s[maxn];
int x, y;

int main(){
	scanf("%d%d", &n, &m);
	mp[++cnt][0] = 0, st[cnt].insert(0), id[cnt] = 0;
	while(n--){
		scanf("%s", s);
		if(s[0] == 's'){
			scanf("%d%d", &x, &y);
			val[cnt] += y;
			if((x ^ m) && !st[cnt].empty()){
				ll mn = *st[cnt].begin();
				if(mp[cnt].find(x) != mp[cnt].end()) st[cnt].erase(st[cnt].find(mp[cnt][x]));
				mp[cnt][x] = mn - y, st[cnt].insert(mp[cnt][x]);
				//printf("%d %lld--\n", x, mp[cnt][x]);
			}
		}else if(s[0] == 'i'){
			scanf("%d", &x);
			id[++cnt] = x;
			if(mp[cnt - 1].find(x) != mp[cnt - 1].end()){
				mp[cnt][x] = val[cnt - 1] + mp[cnt - 1][x];
				st[cnt].insert(mp[cnt][x]);
			}
		}else{
			if(mp[cnt].size() < mp[cnt - 1].size()){
				for(map<int, ll>::iterator it = mp[cnt].begin();it != mp[cnt].end();++it){
					int x = it->first;
					ll y = it->second;
					if(mp[cnt - 1].find(x) != mp[cnt - 1].end()) st[cnt - 1].erase(st[cnt - 1].find(mp[cnt - 1][x]));
					if(x == id[cnt]){
						mp[cnt - 1][x] = val[cnt] + y - val[cnt - 1];
					}else{
						mp[cnt - 1][x] = min(mp[cnt - 1].find(x) != mp[cnt - 1].end() ? mp[cnt - 1][x] : (ll)1e18, val[cnt] + y - val[cnt - 1]);
					}
					st[cnt - 1].insert(mp[cnt - 1][x]);
				}
			}else{
				for(map<int, ll>::iterator it = mp[cnt - 1].begin();it != mp[cnt - 1].end();++it){
					int x = it->first;
					ll y = it->second;
					
					if(x != id[cnt]){
						if(mp[cnt].find(x) != mp[cnt].end()) st[cnt].erase(st[cnt].find(mp[cnt][x]));
						mp[cnt][x] = min(mp[cnt].find(x) != mp[cnt].end() ? mp[cnt][x] : (ll)1e18, val[cnt - 1] + y - val[cnt]);
						//printf("%d %lld--\n", x, mp[cnt][x]);
						st[cnt].insert(mp[cnt][x]);
					}
				}
				swap(mp[cnt], mp[cnt - 1]), swap(st[cnt], st[cnt - 1]), swap(val[cnt], val[cnt - 1]);
			}
			val[cnt] = 0, mp[cnt].clear(), st[cnt].clear();
			--cnt;
			//printf("%d %d %lld--\n", cnt, val[cnt], *st[cnt].begin());
		}
	}
	printf("%lld", *st[1].begin() + val[1]);
}