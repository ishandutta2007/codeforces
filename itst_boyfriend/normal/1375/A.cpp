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

int main(){
	int T , N;
	for(cin >> T ; T ; --T){
		cin >> N;
		for(int i = 1 ; i <= N ; ++i){
			int a; cin >> a; a = abs(a); if(i & 1) a *= -1;
			cout << a << ' ';
		}
		cout << endl;
	}
	return 0;
}