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

int k;

int main(){
	cin >> k;
	for(int i=0; i<(1<<k); i++){
		for(int j=0; j<(1<<k); j++){
			int flip = 0;
			for(int l=0; l<k; l++){
				if((i&j)&(1<<l)){
					flip ^= 1;
				}
			}
			putchar(flip ? '*' : '+');
		}
		puts("");
	}
}