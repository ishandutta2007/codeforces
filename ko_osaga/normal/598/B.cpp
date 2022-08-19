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

string str;
int q;

int main(){
	cin >> str >> q;
	for(int i=0; i<q; i++){
		int s, e, x;
		scanf("%d %d %d",&s, &e, &x);
		x %= (e - s + 1);
		rotate(str.begin()+s-1, str.begin() + e - x, str.begin() + e);
	}
	cout << str;
}