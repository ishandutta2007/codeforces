#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

int T , M , N;

signed main(){
	for(cin >> T ; T ; --T){
		cin >> M >> N;
		puts(__gcd(M , N) == 1 ? "Finite" : "Infinite");
	}
	return 0;
}