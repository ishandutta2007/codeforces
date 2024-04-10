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
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; op.clear(); bool flg = 0;
		for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		do{
			while(calc_mex() != N) put(calc_mex() + 1);
			flg = 1;
			for(int i = 1 ; i <= N ; ++i)
				if(arr[i] != i - 1){flg = 0; put(i); break;}
		}while(!flg);
		cout << op.size() << endl;
		for(int i = 0 ; i < op.size() ; ++i) cout << op[i] << ' ';
		cout << endl;
	}
	return 0;
}