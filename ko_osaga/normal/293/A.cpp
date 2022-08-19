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

int c0, c1, c2, n;
char s1[2000005];
char s2[2000005];

int main(){
	cin >> n >> s1 >> s2;
	for(int i=0; i<2*n; i++){
		if(s1[i] == '1' && s2[i] =='1') c0++;
		else if(s1[i] == '1') c1++;
		else if(s2[i] == '1') c2++;
	}
	c1 += c0%2;
	if(c1 == c2 || c1 + 1 == c2) puts("Draw");
	else if(c1 > c2) puts("First");
	else puts("Second");
}