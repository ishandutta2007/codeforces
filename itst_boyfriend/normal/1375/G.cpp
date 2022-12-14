#include<iostream>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<sstream>
//STL
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
//C++11 needed
#include<unordered_map>
#include<unordered_set>
#include<random>
using namespace std;

const int _ = 2e5 + 7; vector < int > nxt[_]; int N , num[2];

void dfs1(int x , int p , int d){++num[d]; for(auto t : nxt[x]) if(t != p) dfs1(t , x , d ^ 1);}

int main(){
	cin >> N; for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	dfs1(1 , 0 , 0); cout << min(num[1] , num[0]) - 1; return 0;
}