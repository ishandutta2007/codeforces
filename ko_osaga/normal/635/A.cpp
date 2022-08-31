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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int k;
int main(){
	int r, c, n, x[15], y[15], ret = 0;
	cin >> r >> c >> n >> k;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1; i<=r; i++){
		for(int j=i; j<=r; j++){
			for(int k=1; k<=c; k++){
				for(int l=k; l<=c; l++){
					int q = 0;
					for(int m=0; m<n; m++){
						if(i <= x[m] && x[m] <= j && k <= y[m] && y[m] <= l){
							q++;
						}
					}
					if(q >= ::k) ret++;
				}
			}
		}
	}
	cout << ret;
}