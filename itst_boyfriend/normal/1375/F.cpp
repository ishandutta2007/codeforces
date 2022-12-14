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

int T , N , arr[1003];
vector < int > op;
int calc_mex(){
	static bool vis[1003]; memset(vis , 0 , sizeof(vis));
	for(int i = 1 ; i <= N ; ++i) vis[arr[i]] = 1;
	int pos = 0; while(vis[pos]) ++pos;
	return pos;
}
void put(int x){op.push_back(x); arr[x] = calc_mex();}

int main(){
	long long arr[4]; cin >> arr[1] >> arr[2] >> arr[3];
	cout << "First" << endl << 2000000000 << endl;
	int id; cin >> id; arr[id] += 2000000000;
	int pos[4] = {0,1,2,3}; sort(pos + 1 , pos + 4 , [&](int p , int q){return arr[p] < arr[q];});
	long long x1 = arr[pos[2]] - arr[pos[1]] , x2 = arr[pos[3]] - arr[pos[2]];
	cout << x1 + 2 * x2 << endl; cin >> id;
	if(id == pos[1]) cout << x2 << endl;
	else cout << x1 + x2 << endl;
	return 0;
}