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

int n, m;
char str[505][505];
int s1[505][505], s2[505][505];

int main(){
	set<lint> st;
	lint s, e;
	cin>>s>>e;
	int ret = 0;
	for(int i=0; i<62; i++){
		lint t = (1ll<<i)-1;
		for(int j=0; j<i-1; j++){
			lint u = t ^ (1ll << j);
			if(s <= u && u <= e) st.insert(u);
		}
	}
	cout << st.size();
}