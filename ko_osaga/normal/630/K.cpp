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
typedef pair<int,int> pi;

int p[4] = {2, 3, 5, 7};

int main(){
	lint n, ret = 0;
	cin >> n;
	for(int i=0; i<16; i++){
		int cnt = 0, mul = 1;
		for(int j=0; j<4; j++){
			if((i >> j) & 1){
				cnt++;
				mul *= p[j];
			}
		}
		if(cnt & 1) ret -= n / mul;
		else ret += n / mul;
	}
	cout << ret;
}