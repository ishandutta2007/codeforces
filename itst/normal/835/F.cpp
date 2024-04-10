#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
//This code is written by Itst
using namespace std;

const int MAXN = 2e5 + 9;
struct Edge{
	int end , upEd , w;
}Ed[MAXN << 1];
int head[MAXN] , N , cntEd = 1;
bool vis[MAXN];

inline void addEd(int a , int b , int c){
	Ed[++cntEd] = (Edge){b , head[a] , c};
	head[a] = cntEd;
}

int find(int x , int uped){
	vis[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(i != (uped ^ 1))
			if(!vis[Ed[i].end]){
				int t = find(Ed[i].end , i);
				if(t) return t == x ? 0 : t;
			}
			else
				return Ed[i].end;
	return vis[x] = 0;
}

long long sum , dp[MAXN] , len[MAXN] , cir = 1e18 , ans;
vector < int > incir;
bool pos[MAXN];

void dfs(int x , int p){
	if(vis[x]) incir.push_back(x);
	pos[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end] && Ed[i].end != p){
			dfs(Ed[i].end , x);
			ans = max(ans , dp[x] + dp[Ed[i].end] + Ed[i].w);
			dp[x] = max(dp[x] , dp[Ed[i].end] + Ed[i].w);
		}
		else
			if(vis[Ed[i].end] && !pos[Ed[i].end]){
				len[Ed[i].end] = len[x] + Ed[i].w;
				dfs(Ed[i].end , x);
			}
}

#define PLI pair < long long , int >
#define st first
#define nd second
set < PLI > s1 , s2;
set < PLI > :: iterator it1 , it2;

void solve(){
	for(int i = 0 ; i < incir.size() ; ++i){
		s1.insert(PLI(dp[incir[i]] + len[incir[i]] , i));
		s2.insert(PLI(dp[incir[i]] - len[incir[i]] , i));
	}
	for(int i = 0 ; i < incir.size() ; ++i){
		it1 = --s1.end(); it2 = --s2.end();
		if(it1->nd == it2->nd){
			long long t = (--it1)->st + it2->st;
			cir = min(cir , max(t , (++it1)->st + (--it2)->st));
		}
		else
			cir = min(cir , it1->st + it2->st);
		s1.erase(s1.find(PLI(dp[incir[i]] + len[incir[i]] , i)));
		s2.erase(s2.find(PLI(dp[incir[i]] - len[incir[i]] , i)));
		s1.insert(PLI(dp[incir[i]] + len[incir[i]] + sum , i));
		s2.insert(PLI(dp[incir[i]] - len[incir[i]] - sum , i));
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int a , b , c;
		cin >> a >> b >> c;
		addEd(a , b , c); addEd(b , a , c);
	}
	find(1 , 0);
	for(int i = 1 ; i <= N ; ++i)
		if(vis[i]){
			dfs(i , 0);
			break;
		}
	for(int i = 0 ; i < incir.size() ; ++i)
		for(int j = head[incir[i]] ; j ; j = Ed[j].upEd)
			if(Ed[j].end == incir[(i + 1) % incir.size()]){
				sum += Ed[j].w;
				if(incir.size() > 2)
					break;
			}
	if(incir.size() == 2) sum >>= 1;
	solve();
	cout << max(ans , cir);
	return 0;
}