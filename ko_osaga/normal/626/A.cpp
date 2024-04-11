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
const int mod = 1e9 + 9;

int main(){
	int n, ret = 0;
	char str[205];
	cin >> n >> str;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int t1 = count(str+i, str+j+1, 'U');
			int t2 = count(str+i, str+j+1, 'R');
			int t3 = count(str+i, str+j+1, 'L');
			int t4 = count(str+i, str+j+1, 'D');
			if(t1 == t4 && t3 == t2) ret++;
		}
	}
	cout << ret;
}