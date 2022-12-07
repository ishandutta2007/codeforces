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

int main() {
    //freopen("in","r",stdin);
    //freopen("nout","w",stdout);
    
    ll n,k; cin >> n >> k;
    int p; cin >> p;
	
    ll sh;
    if (n & 1) {
	if (k <= 2) sh = k;
	else {
	    if (k <= (n-3)/2 + 2) sh = 2;
	    else sh = (1 + k - ((n-3)/2 + 2)) * 2;
	}
    } else {
	if (k <= 1) sh = k;
	else {
	    if (k <= (n / 2)) sh = 1;
	    else sh = (k - (n/2)) * 2 + 1;
	}
    }  
    if (n == k) sh = n;
    ll left = k - sh;
    
     
    //cout << sh << endl;
    //cout << left << endl;
    
    while (p--) {
	ll x; cin >> x;
	x = n - x + 1;
	
	if (x <= sh) { 
	    putchar('X');
	    continue;
	}
	x -= sh;
	if (x <= left * 2) {
	    if (x & 1) putchar('.');
	    else putchar('X');
	    continue;
	}
	putchar('.');
    }
    
    
    return 0;
}