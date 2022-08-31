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

// 5   52

int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int x;
	string y, z;
	cin >> x >> y >> z;
	if(z == "week"){
		cout << (x == 6 || x == 5 ? 53 : 52);
	}
	else{
		int ret = 0;
		for(int i=0; i<12; i++){
			if(x <= day[i]) ret++;
		}
		cout << ret;
	}
}