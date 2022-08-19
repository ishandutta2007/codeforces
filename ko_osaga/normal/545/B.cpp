#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<double, int> pi;

int fcnt = 0;

string s, t;
int main(){
	cin >> s >> t;
	for(int i=0; i<s.size(); i++){
		if(s[i] != t[i]) fcnt++;
	}
	if(fcnt&1){
		cout << "impossible";
		return 0;
	}
	fcnt /= 2;
	for(int i=0; i<s.size(); i++){
		if(fcnt && s[i] != t[i]) s[i] ^= 1, fcnt--;
	}
	cout << s;
}