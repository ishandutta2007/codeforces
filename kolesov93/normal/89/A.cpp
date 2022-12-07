#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;
long long n,m,k;
#define N 111111
long long a[N];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) {
	int x;
	scanf("%d",&x);
	a[i] = x;
    }
    
    if (n % 2 == 0) {
	cout << 0 << endl;
	return 0;
    }
    
    long long mx = a[0];
    for (int i=0;i<n;i+=2)
	if (a[i] < mx) mx = a[i];
	
    long long q = (n+1) / 2;
    long long iter = m / q;
    cout << min(mx, k*iter) << endl;
     
    return 0;
}