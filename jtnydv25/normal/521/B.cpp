#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;
const int mod = 1e9 + 9;

int m, x[N], y[N];

map<pair<int, int>, int> mp;
set<pair<int, int>> st;
vector<int> con[N];
set<pair<int, pair<int, int>>> Free;
bool xyz = 1;
bool checkFree(int x, int y){
	if( (st.find({x, y + 1}) != st.end()) && (st.find({x - 1, y}) == st.end()) && (st.find({x + 1, y}) == st.end())){
		return 0;
	}
	if(st.find({x + 1, y + 1}) != st.end() && st.find({x + 1, y}) == st.end() && st.find({x + 2, y}) == st.end()){
		return 0;
	}
	if((st.find({x - 1, y + 1}) != st.end()) && (st.find({x - 1, y}) == st.end()) && (st.find({x - 2, y}) == st.end()) ){
		return 0;
	}
	return 1;
}

inline void process(int x, int y){
	int val = mp[make_pair(x, y)];
	if(!val) return;
	auto pr = make_pair(val, make_pair(x, y));
	bool b = checkFree(x, y);
	if(b){
		Free.insert(pr);
	}
	else{
		auto it = Free.find(pr);
		if(it != Free.end()){
			Free.erase(pr);
		}
	}
}

void remove(int x, int y){
	st.erase(make_pair(x, y));
	process(x, y - 1);
	process(x + 1, y);	
	process(x - 1, y);
	process(x - 1, y - 1);
	process(x - 2, y);
	process(x + 1, y - 1);
	process(x + 2, y);
}

int main(){
	int ans = 0 % mod;
	sd(m);
	for(int i = 0; i < m; i++){
		sd(x[i]); sd(y[i]);
		mp[{x[i], y[i]}] = i + 1;
		st.insert(make_pair(x[i], y[i]));
	}

	for(int i = 0; i < m; i++){
		process(x[i], y[i]);
	}
	for(int i = 1; i <= m; i++){
		auto it2 = Free.begin();
		if(i & 1){
			it2 = Free.end();
			it2--;
		}
		if(it2 == Free.end()) assert(0);
		auto it = *it2;
		ans = (ans * 1ll * m + (it.first - 1)) % mod;
		Free.erase(it);
		mp[make_pair(it.second.first, it.second.second)] = 0;
		remove(it.second.first, it.second.second);
	}
	printf("%d\n", ans);
}