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

int perm[100005];
int n, m;
int s[100005], e[100005];
set<pi> stt;

bool bad(){
	for(int i=0; i<m; i++){
		int st = perm[i+1], ed = perm[(i+1)%n+1];
		if(stt.find(pi(st, ed)) != stt.end()) return 1;
	}
	return 0;
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		perm[i] = n+1-i;
	}
	for(int i=0; i<m; i++){
		scanf("%d %d",&s[i], &e[i]);
		stt.insert(pi(s[i], e[i]));
		stt.insert(pi(e[i], s[i]));
	}
	for(int i=0; i<100 && bad(); i++){
		random_shuffle(perm+1, perm+n+1);
	}
	if(bad()){
		cout << -1;
		return 0;
	}
	for(int i=0; i<m; i++){
		printf("%d %d\n",perm[i+1], perm[(i+1)%n+1]);
	}
}