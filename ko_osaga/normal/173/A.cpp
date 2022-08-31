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

int n, a, b;
string p, q;
string tp, tq;
int ret1, ret2;

int win(char a, char b){
	if(a == 'R' && b == 'S') return 1;
	if(a == 'S' && b == 'P') return 1;
	if(a == 'P' && b == 'R') return 1;
	return 0;
}

int main(){
	cin >> n >> tp >> tq;
	for(int i=0; i<tq.size(); i++){
		p = p + tp;
	}
	for(int i=0; i<tp.size(); i++){
		q = q + tq;
	}
	int l = tp.size() * tq.size();
	for(int i=0; i<l; i++){
		ret1 += win(p[i], q[i]);
		ret2 += win(q[i], p[i]);
	}
	ret1 *= n/l;
	ret2 *= n/l;
	for(int i=0; i<n%l; i++){
		ret1 += win(p[i], q[i]);
		ret2 += win(q[i], p[i]);
	}
	printf("%d %d",ret2, ret1);
}