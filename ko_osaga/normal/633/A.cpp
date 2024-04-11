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

int a, b, c;

int main(){
	cin >> a >> b >> c;
	for(int i=0; i<=c; i++){
		if(i % a) continue;
		if((c - i) % b) continue;
		puts("Yes");
		return 0;
	}
	puts("No");
}