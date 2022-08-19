#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

lint a[36] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8092, 16184, 32368, 64736, 129472, 258944, 517888, 1035776, 2071552, 4143104, 8286208, 16572416, 33144832, 66289664, 132579328, 265158656, 530317312, 1060634624, 2121269248, 4242538496ll, 8485076992ll, 16970153984ll, 33940307968ll};

int main(){
	int n;
	cin >> n;
	int ret = 0;
	while(n){
		if(n%8 == 1) ret++;
		n /= 8;
	}
	cout << ret;
}