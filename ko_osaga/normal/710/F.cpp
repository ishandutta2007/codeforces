#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

const int MAXN = 300005, MAXC = 26;
struct aho_corasick{
	int trie[MAXN][MAXC], fail[MAXN], term[MAXN], piv;
	void clear(){
		for(int i=0; i<=piv; i++){
			for(int j=0; j<MAXC; j++) trie[i][j] = 0;
			fail[i] = term[i] = 0;
		}
		piv = 0;
	}
	void init(vector<string> &v, vector<int> &w){
		clear();
		int idx = 0;
		for(auto &i : v){
			int p = 0;
			for(auto j : i){
				j -= 'a';
				if(!trie[p][j]) trie[p][j] = ++piv;
				p = trie[p][j];
			}
			term[p] += w[idx++];
		}
		queue<int> que;
		for(int i=0; i<MAXC; i++){
			if(trie[0][i]) que.push(trie[0][i]);
		}
		while(!que.empty()){
			int x = que.front();
			que.pop();
			for(int i=0; i<MAXC; i++){
				if(trie[x][i]){
					int p = fail[x];
					while(p && !trie[p][i]) p = fail[p];
					p = trie[p][i];
					fail[trie[x][i]] = p;
					term[trie[x][i]] += term[p];
					que.push(trie[x][i]);
				}
			}
		}
	}
	lint query(string &s){
		int p = 0;
		lint ret = 0;
		for(auto i : s){
			i -= 'a';
			while(p && !trie[p][i]) p = fail[p];
			p = trie[p][i];
			ret += term[p];
		}
		return ret;
	}
}ac[20];

vector<string> s[20];
vector<int> t[20];

void upload(string &str, int val){
	s[0].push_back(str);
	t[0].push_back(val);
	for(int i=0; i<20; i++){
		if(s[i].size() > (1<<i)){
			for(int j=0; j<s[i].size(); j++){
				s[i+1].push_back(s[i][j]);
				t[i+1].push_back(t[i][j]);
			}
			s[i].clear();
			t[i].clear();
			ac[i].clear();
		}
		else{
			ac[i].init(s[i], t[i]);
			break;
		}
	}
}

char buf[300005];
int main(){
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		int t;
		scanf("%d",&t);
		if(t == 1 || t == 2){
			scanf("%s", buf);
			string s = buf;
			upload(s, (t == 1 ? 1 : -1));
		}
		else{
			scanf("%s", buf);
			string s = buf;
			lint ret = 0;
			for(int i=0; i<20; i++) ret += ac[i].query(s);
			printf("%lld\n", ret);
			fflush(stdout);
		}
	}
}