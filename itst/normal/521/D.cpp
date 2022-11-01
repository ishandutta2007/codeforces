#include<bits/stdc++.h>
using namespace std;

/*
  REMEMBER:
  1.Think TWICE, code ONCE!
  Are there any counterexamples to your algo?
	
  2.Be careful about the BOUNDARIES in your algo!
  N=1? P=1? Is P a prime? Something about 0?
	
  3.Never make STUPID MISTAKES!
  Integer overflow? Array size? Time complexity? Memory usage? Precition error?
*/

#define ld long double
#define PLI pair < ld , int >
const int _ = 1e5 + 7;
vector < PLI > arr[_];
int N , M , K , op[_] , plc[_] , x[_] , val[_] , id[_] , pos[_]; bool vis[_];
priority_queue < PLI > q;

int main(){
	cin >> N >> M >> K;
	for(int i = 1 ; i <= N ; ++i) cin >> val[i];
	for(int i = 1 ; i <= M ; ++i){
		cin >> op[i] >> plc[i] >> x[i];
		if(op[i] == 1) id[plc[i]] = x[id[plc[i]]] < x[i] ? i : id[plc[i]];
		else if(op[i] == 2) arr[plc[i]].push_back(make_pair(x[i] , i));
		else arr[0].push_back(make_pair(x[i] , i));
	}
	for(int i = 1 ; i <= N ; ++i) if(x[id[i]] > val[i]) arr[i].push_back(PLI(x[id[i]] - val[i] , id[i]));
	for(int i = 0 ; i <= N ; ++i) sort(arr[i].begin() , arr[i].end() , [&](PLI p , PLI q){return p.first > q.first;});
	for(int i = 1 ; i <= N ; ++i){
		long long sum = val[i] , tmp;
		for(int j = 0 ; j < arr[i].size() ; ++j){tmp = sum + arr[i][j].first; arr[i][j].first = tmp * 1.0 / sum; sum = tmp;}
	}
	for(int i = 0 ; i <= N ; ++i) if(arr[i].size()) q.push(PLI(arr[i][0].first , i));
	int cnt = 0;
	while(K-- && !q.empty()){
		int t = q.top().second; q.pop(); vis[arr[t][pos[t]++].second] = 1; ++cnt;
		if(pos[t] != arr[t].size()) q.push(PLI(arr[t][pos[t]].first , t));
	}
	cout << cnt << endl;
	for(int i = 1 ; i <= 3 ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(vis[j] && op[j] == i) cout << j << ' ';
	return 0;
}