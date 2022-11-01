#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; vector < int > nxt[_]; int N , num[2];

void dfs1(int x , int p , int d){++num[d]; for(auto t : nxt[x]) if(t != p) dfs1(t , x , d ^ 1);}

int main(){
	cin >> N; for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	dfs1(1 , 0 , 0); cout << min(num[1] , num[0]) - 1; return 0;
}