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

char str[1000005];
int ret[1000005], lp, rp;
int main(){
	cin >> str;
	rp = strlen(str);
	for(int i=0; str[i]; i++){
		if(str[i] == 'l') ret[--rp] = i+1;
		else ret[lp++] = i+1;
	}
	for(int i=0; str[i]; i++){
		printf("%d\n",ret[i]);
	}
}