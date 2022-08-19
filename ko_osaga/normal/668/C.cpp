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
typedef pair<int, int> pi;

int n;
llf p1[100005], p2[100005];
llf sp1[100005], sp2[100005];
llf sa[100005], sb[100005];
lint fuck1[100005], fuck2[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		double p1;
		cin >> p1;
		fuck1[i] = ceil(p1 * 1e8-0.5) + fuck1[i-1];
		sp1[i] = (llf)fuck1[i] * 1e-8;
	}
	for(int i=1; i<=n; i++){
		double p2;
		cin >> p2;
		fuck2[i] = ceil(p2 * 1e8-0.5) + fuck2[i-1];
		sp2[i] = (llf)fuck2[i] * 1e-8;
	}
	llf sum = 0;
	for(int i=1; i<=n; i++){
		llf sum = sp1[i] + sp2[i]; // s(a) + s(b)
		llf prod = sp1[i]; // s(a) * s(b);
		llf b24ac = sqrt(sum * sum - 4 * prod);
		sa[i] = (sum + b24ac) / 2;
		sb[i] = (sum - b24ac) / 2;
	}
	for(int i=1; i<=n; i++){
		printf("%.10f ",(double)(sa[i] - sa[i-1]));
	}
	puts("");
	for(int i=1; i<=n; i++){
		printf("%.10f ",(double)(sb[i] - sb[i-1]));
	}

}