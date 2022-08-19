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
char str[100005];

int ret = 1;
int main(){
	cin >> n >> str;
	for(int i=0; i<n-1; i++){
		ret += (str[i] != str[i+1]);
	}
	ret = min(ret + 2, n);
	cout << ret;
}