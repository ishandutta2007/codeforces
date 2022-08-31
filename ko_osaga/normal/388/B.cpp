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

int n;
bool adj[1005][1005];

int main(){
	cin >> n;
	adj[1][3] = 1;
	for(int i=4; i<=67; i++){
		adj[i-1][i] = 1;
	}
	adj[3][68] = adj[68][69] = 1;
	int p = 69;
	n--;
	for(int i=5; i<=66; i+=2){
		if(n%2 == 1){
			adj[p][i+1] = 1;
			n--;
		}
		if(n >= 2){
			adj[p][p+1] = 1;
			adj[p][p+2] = 1;
			adj[p+1][p+3] = 1;
			adj[p+2][p+3] = 1;
			p += 3;
			n /= 2;
		}
	}
	adj[67][2] = 1;
	printf("%d\n",p);
	for(int i=1; i<=p; i++){
		for(int j=1; j<=p; j++){
			putchar((adj[i][j] || adj[j][i]) ? 'Y' : 'N');
		}
		puts("");
	}
}