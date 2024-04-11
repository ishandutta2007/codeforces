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

int g(int x, int y){
	return y ? g(y, x%y) : x;
}

set<int> s;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			for(int k=2; k<=j; k++){
				if(i % k == 0 && j % k != 0){s.insert(k);break;}
				if(i % k != 0 && j % k == 0){s.insert(k);break;}
			}
		}
	}
	s.insert(1);
	s.erase(1);
	printf("%d\n",s.size());
	for(auto &i : s){
		printf("%d ",i);
	}

}