#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair < int , int >
const int _ = 1e5 + 7 , lim = 151; int N , Q , id[_] , ans[_]; vector < pii > pot[_];

int ch[_][26] , fa[_] , fail[_] , cnode = 1;
int ins(string s){int rt = 1; for(auto t : s){if(!ch[rt][t - 'a']) fa[ch[rt][t - 'a'] = ++cnode] = rt; rt = ch[rt][t - 'a'];} return rt;}

vector < int > nxt[_]; int dfn[_] , ind[_] , sz[_] , ts;
void dfs(int x){ind[dfn[x] = ++ts] = x; sz[x] = 1; for(auto t : nxt[x]){dfs(t); sz[x] += sz[t];}}
void build(){
	fail[1] = 1; queue < int > q; for(int i = 0 ; i < 26 ; ++i) if(ch[1][i]){fail[ch[1][i]] = 1; q.push(ch[1][i]);} else ch[1][i] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = 0 ; i < 26 ; ++i) if(ch[t][i]){fail[ch[t][i]] = ch[fail[t]][i]; q.push(ch[t][i]);} else ch[t][i] = ch[fail[t]][i];
	}
	for(int i = 2 ; i <= cnode ; ++i){nxt[fail[i]].push_back(i);} dfs(1);
}

int mrk[_] , sum[_];
void solve(int x){
	memset(mrk , 0 , sizeof(mrk)); for(int i = id[x] ; i ; i = fa[i]) mrk[i] = 1;
	for(int i = cnode ; i ; --i) mrk[fail[ind[i]]] += mrk[ind[i]];
	for(int i = 1 ; i <= N ; ++i) sum[i] = sum[i - 1] + mrk[id[i]];
	for(auto t : pot[x]) ans[abs(t.second)] += (t.second < 0 ? -1 : 1) * sum[t.first];
}

#define lowbit(x) ((x) & -(x))
int arr[_]; void add(int x , int v){while(x <= cnode){arr[x] += v; x += lowbit(x);}}
int query(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cin >> N >> Q; for(int i = 1 ; i <= N ; ++i){string s; cin >> s; id[i] = ins(s);}
	for(int i = 1 ; i <= Q ; ++i){int l , r , k; cin >> l >> r >> k; pot[k].push_back(pii(l - 1 , -i)); pot[k].push_back(pii(r , i));}
	build();
	
	struct qry{int a , b , id;}; vector < qry > now;
	for(int i = 1 ; i <= N ; ++i) if(pot[i].size() <= lim) for(auto t : pot[i]) now.push_back((qry){t.first , i , t.second}); else solve(i);
	sort(now.begin() , now.end() , [&](qry p , qry q){return p.a < q.a;}); int pos = 0; while(pos < now.size() && now[pos].a == 0) ++pos;
	for(int i = 1 ; i <= N ; ++i){
		add(dfn[id[i]] , 1); add(dfn[id[i]] + sz[id[i]] , -1);
		while(pos < now.size() && now[pos].a == i){
			int sum = 0; for(int t = id[now[pos].b] ; t ; t = fa[t]) sum += query(dfn[t]);
			ans[abs(now[pos].id)] += (now[pos].id < 0 ? -1 : 1) * sum; ++pos;
		}
	}
	for(int i = 1 ; i <= Q ; ++i) cout << ans[i] << '\n';
	return 0;
}