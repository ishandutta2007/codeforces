#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
const int _ = 1e6 + 7;
int ch[_][26] , fail[_] , id[_] , ans[_] , rt , cnt = 1 , N , M;
vector < PII > qry[_];

int append(int id , int p){return ch[id][p] ? ch[id][p] : (ch[id][p] = ++cnt);}
int append(string str){int cur = rt; for(auto t : str) cur = append(cur , t - 'a'); return cur;}

vector < int > nxt[_]; bool add[_][26];
void build(){
	queue < int > q; fail[1] = 1;
	for(int i = 0 ; i < 26 ; ++i)
		if(ch[1][i]){fail[ch[1][i]] = 1; q.push(ch[1][i]);} else add[1][i] = ch[1][i] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop(); nxt[fail[t]].push_back(t);
		for(int i = 0 ; i < 26 ; ++i)
			if(ch[t][i]){fail[ch[t][i]] = ch[fail[t]][i]; q.push(ch[t][i]);}
			else add[t][i] = ch[t][i] = ch[fail[t]][i];
	}
}

int dfn[_] , sz[_] , ts;
void dfs1(int x){dfn[x] = ++ts; sz[x] = 1; for(auto t : nxt[x]){dfs1(t); sz[x] += sz[t];}}

#define lowbit(x) (x & -x)
namespace BIT{
	int arr[_];
	void add(int x , int val){while(x <= cnt){arr[x] += val; x += lowbit(x);}}
	int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}
}
void dfs2(int x){
	BIT::add(dfn[x] , 1);
	for(auto t : qry[x]) ans[t.second] = BIT::qry(dfn[t.first] + sz[t.first] - 1) - BIT::qry(dfn[t.first] - 1);
	for(int i = 0 ; i < 26 ; ++i) if(!add[x][i]) dfs2(ch[x][i]);
	BIT::add(dfn[x] , -1);
}

int main(){
	id[0] = rt = 1; ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int tp , pos; char c; cin >> tp;
		if(tp == 1) pos = 0; else cin >> pos;
		cin >> c; id[i] = append(id[pos] , c - 'a');
	}
	cin >> M;
	for(int i = 1 ; i <= M ; ++i){
		int pos; string str; cin >> pos >> str; qry[id[pos]].push_back(PII(append(str) , i));
	}
	build(); dfs1(1); dfs2(1);
	for(int i = 1 ; i <= M ; ++i) printf("%d\n" , ans[i]);
	return 0;
}