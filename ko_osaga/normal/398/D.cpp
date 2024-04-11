#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int B = 500;

int n, m, q;
vector<int> L[50005];
vector<int> heavy;
unordered_set<int> H[50005];

int hchk[50005];
int on[50005], sz[50005];

void online(int v){
	on[v] = 1;
	if(hchk[v]){
		for(auto &i : heavy){
			if(H[v].find(i) != H[v].end()) sz[i]++;
		}
	}
	else{
		for(auto &i : L[v]){
			sz[i]++;
		}
	}
}

void offline(int v){
	on[v] = 0;
	if(hchk[v]){
		for(auto &i : heavy){
			if(H[v].find(i) != H[v].end()) sz[i]--;
		}
	}
	else{
		for(auto &i : L[v]){
			sz[i]--;
		}
	}
}

void add_friend(int u, int v){
	if(hchk[u]){
		H[u].insert(v);
		if(on[v]) sz[u]++;
	}
	else{
		L[u].push_back(v);
		if(on[v]) sz[u]++;
		if(L[u].size() == B){
			sz[u] = 0;
			H[u].clear();
			for(auto &i : L[u]){
				H[u].insert(i);
				if(on[i]) sz[u]++;
			}
			heavy.push_back(u);
			hchk[u] = 1;
		}
	}
}

void del_friend(int u, int v){
	if(hchk[u]){
		H[u].erase(v);
		if(H[u].size() == B-1){
			L[u].clear();
			for(auto &i : H[u]) L[u].push_back(i);
			heavy.erase(find(heavy.begin(), heavy.end(), u));
			hchk[u] = 0;
		}
	}
	else{
		L[u].erase(find(L[u].begin(), L[u].end(), v));
	}
	if(on[u]) sz[v]--;
}

int count_online_friends(int x){
	if(hchk[x]) return sz[x];
	int ret = 0;
	for(auto &i : L[x]){
		if(on[i]) ret++;
	}
	return ret;
}

int main(){
	cin >> n >> m >> q;
	int t, u;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&u);
		online(u);
	}
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		add_friend(s, e);
		add_friend(e, s);
	}
	char x[5];
	while(q--){
		scanf("%s",x);
		if(*x == 'O'){
			scanf("%d",&u);
			online(u);
		}
		if(*x == 'F'){
			scanf("%d",&u);
			offline(u);
		}
		if(*x == 'A'){
			scanf("%d %d",&t,&u);
			add_friend(t, u);
			add_friend(u, t);
		}
		if(*x == 'D'){
			scanf("%d %d",&t,&u);
			del_friend(t, u);
			del_friend(u, t);
		}
		if(*x == 'C'){
			scanf("%d",&u);
			printf("%d\n", count_online_friends(u));
		}
	}
}