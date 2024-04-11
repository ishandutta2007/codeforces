#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
#define N 9
int n,k,A,a[N],b[N];
double pos[1<<N],ans=0,w[N];
int lim;

void rec(int l, int m) {
    if (l == n) {
	double cand = 0;
	for (int msk=0;msk<lim;msk++) {
	    double cur = 1;
	    int cnt = 0;
	    for (int i=0;i<n;i++)
		if (msk & (1 << i)) { 
		    cur *= w[i];
		    cnt++;
		} else cur *= (1 - w[i]);
	    if (cnt > (double) n / 2.0) cand += cur;
	    else {
		int nmsk = (lim - 1) ^ msk;
		cand += cur * pos[nmsk];
	    }
	}
	
	if (cand > ans) ans = cand;
	return;
    }
    
    for (int i=0;i<=m;i++) {
	int res = min(100,b[l] + i*10);
	w[l] = res / 100.0;
	rec(l+1,m-i);
    }
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> n >> k >> A;
    for (int i=0;i<n;i++) cin >> a[i] >> b[i];
    lim = 1 << n;
    
    for (int i=0;i<lim;i++) {
	int sum = 0;
	for (int j=0;j<n;j++)
	    if (i & (1 << j)) sum += a[j];
	pos[i] = (double) A / (double) ((double) A + (double) sum);
    }
    
    rec(0,k);
    printf("%.8f",ans); cout << endl;
    
    return 0;
}