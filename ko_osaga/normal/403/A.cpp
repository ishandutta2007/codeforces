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

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, p;
		cin >> n >> p;
		for(int i=1; i<=2; i++){
			for(int j=0; j<n; j++){
				int p = (j + i) % n;
				printf("%d %d\n",j+1, p+1);
			}
		}
		int q = 0;
		for(int i=3; i<=n; i++){
			for(int j=0; j<n; j++){
				if(p){
					printf("%d %d\n",j+1, (j+i)%n + 1);
					p--;
				}
			}
		}
	}
}