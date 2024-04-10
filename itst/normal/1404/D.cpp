#include<bits/stdc++.h>
using namespace std;

const int _ = 2e6 + 7; vector < int > nxt[_] , node[_]; int col[_] , sum[3] , N;

void dfs(int x , int c){
	sum[c] = (sum[c] + x) % (2 * N); col[x] =c;
	for(auto t : nxt[x]) if(!col[t]) dfs(t , 3 - c);
}

int main(){
	ios::sync_with_stdio(0);
	cin >> N;
	if(!(N & 1)){
		cout << "First" << endl;
		for(int i = 1 ; i <= N ; ++i) cout << i << ' ';
		for(int i = 1 ; i <= N ; ++i) cout << i << ' ';
		cout << endl;
	}else{
		cout << "Second" << endl;
		for(int i = 1 ; i <= 2 * N ; ++i){int t; cin >> t; node[t].push_back(i);}
		for(int i = 1 ; i <= N ; ++i){nxt[node[i][0]].push_back(node[i][1]); nxt[node[i][1]].push_back(node[i][0]);}
		for(int i = 1 ; i <= N ; ++i){nxt[i].push_back(i + N); nxt[i + N].push_back(i);}
		for(int i = 1 ; i <= 2 * N ; ++i) if(!col[i]) dfs(i , 1);
		int flag = sum[1] == 0 ? 1 : 2;
		for(int i = 1 ; i <= 2 * N ; ++i) if(col[i] == flag) cout << i << ' ';
		cout << endl;
	}
	return 0;
}