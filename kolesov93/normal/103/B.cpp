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
int w[1111],n,m;

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

int main() {
    //freopen("in","r",stdin);
    //freopen("nout","w",stdout);
    
    cin >> n >> m;
    if (n != m) {
	puts("NO");
	return 0;
    }
    
    for (int i=1;i<=n;i++) w[i] = i;
    
    for (int i=1;i<=m;i++) {
	int a,b; cin >> a >> b;
	w[fath(a)] = fath(b);
    }
    
    for (int i=2;i<=n;i++)
	if (fath(i) != fath(i-1)) { 
	    puts("NO");
	    return 0;
	}
    
    puts("FHTAGN!");
    
    return 0;
}