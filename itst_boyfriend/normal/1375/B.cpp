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

const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int arr[303][303] , N , M , T;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; bool flg = 1;
		for(int i = 1 ; i <= N ; ++i)
			for(int j = 1 ; j <= M ; ++j){
				int cnt = 0 , a; cin >> a;
				for(int k = 0 ; k < 4 ; ++k){
					int x = i + dir[k][0] , y = j + dir[k][1];
					if(x > 0 && x <= N && y > 0 && y <= M) ++cnt;
				}
				flg &= a <= cnt; arr[i][j] = cnt;
			}
		if(flg){
			cout << "YES" << endl;
			for(int i = 1 ; i <= N ; ++i)
				for(int j = 1 ; j <= M ; ++j)
					cout << arr[i][j] << " \n"[j == M];
		}else cout << "NO" << endl;
	}
	return 0;
}