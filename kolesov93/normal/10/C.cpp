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
int n,d[1111111];
ll ans,w[11];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> n;
    int lim = max(100,n);
    for (int i=1;i<=lim;i++) {
	if (i % 9 == 0) d[i] = 9;
	else d[i] = i % 9;
	
	if (i <= n) w[ d[i] ]++;
    }
    
    for (int A=1;A<=9;A++)
	for (int B=A;B<=9;B++) {
	    int prod = d[A * B];
	    
	    if (A == B) ans += w[A] * w[A] * w[prod];
	    else ans += 2 * w[A] * w[B] * w[prod];
	}
    
    for (int A=1;A<=n;A++) {
	int lim = n / A;
	for (int B=1;B<=lim;B++)
	    if (d[A * B] == d[d[A] * d[B]]) ans--;
    }
    
    cout << ans << endl;
    
    return 0;
}