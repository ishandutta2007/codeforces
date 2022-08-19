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

int x, y, n;

int main(){
	x = y = 1;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		if(s == "UL" || s == "DR") x++;
		else if(s == "UR" || s == "DL") y++;
		else x++, y++;
	}
	cout << 1ll * x * y;
}