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

int c0[200005], c1[200005];
string s1, s2;

int main(){
	cin >> s1 >> s2;
	for(int i=0; i<s2.size(); i++){
		if(i){
			c1[i] = c1[i-1]; c0[i] = c0[i-1];
		}
		if(s2[i] == '1') c1[i]++;
		else c0[i]++;
	}
	lint ret = 0;
	for(int i=0; i<s1.size(); i++){
		if(s1[i] == '0'){
			ret += c1[s2.size() - s1.size() + i] - (i ? c1[i-1] : 0);
		}
		else{
			ret += c0[s2.size() - s1.size() + i] - (i ? c0[i-1] : 0);
		}
	}
	cout << ret;
}