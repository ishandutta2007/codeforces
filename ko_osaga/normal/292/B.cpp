#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m;
vector<int> gph[100005];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	if(n < m){
		puts("unknown topology");
		return 0;
	}
	if(n == m){
		for(int i=1; i<=n; i++){
			if(gph[i].size() != 2){
				puts("unknown topology");
				return 0;
			}
		}
		puts("ring topology");
		return 0;
	}
	else{
		bool isbus = 1;
		for(int i=1; i<=n; i++){
			if(gph[i].size() > 2){
				isbus = 0;
			}
		}
		if(isbus){
			puts("bus topology");
			return 0;
		}
		for(int i=1; i<=n; i++){
			if(gph[i].size() == n-1){
				puts("star topology");
				return 0;
			}
		}
		puts("unknown topology");
		return 0;
	}
}