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
#define N 555555
#define MOD 1000003
struct cell {
    int l,r,u,d;
} cx[N],cy[N],ex[2],ey[2];
int n,m;
ll f[N][2][2];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for (int y=1;y<=n;y++)
	for (int x=1;x<=m;x++) {
	    char c = getchar();
	    while ((c < '0' || c > '9') && c != '.') c = getchar();
	    if (c == '.') continue;
	    int num = c - '0';
	    
	    if (num == 1 || num == 2) {
		if (x & 1) cy[y].r = 1;
		else cy[y].l = 1;
	    } else {
		if (x & 1) cy[y].l = 1;
		else cy[y].r = 1;
	    } 
	    
	    if (num == 1 || num == 4) {
		if (y & 1) cx[x].d = 1;
		else cx[x].u = 1;
	    } else {
		if (y & 1) cx[x].u = 1;
		else cx[x].d = 1;
	    }
	}
    
    cy[1].l |= cx[1].l;
    cy[1].r |= cx[1].r;
    cy[1].d |= cx[1].d;
    cy[1].u |= cx[1].u;
    
    if (!cy[n].l) {
	if (!cy[n].d) f[0][0][0] = 1;
	if (!cy[n].u) f[0][0][1] = 1;
    }
    if (!cy[n].r) {
	if (!cy[n].d) f[0][1][0] = 1;
	if (!cy[n].u) f[0][1][1] = 1;
    }
	
    int cur = 0;
    for (int y=n-1;y;y--) {
	cur++;
	
	if (!cy[y].l && !cy[y].u) f[cur][0][1] = (f[cur-1][0][0] + f[cur-1][1][0]) % MOD;
	if (!cy[y].l && !cy[y].d) f[cur][0][0] = (f[cur-1][0][1] + f[cur-1][1][1]) % MOD;
	if (!cy[y].r && !cy[y].d) f[cur][1][0] = (f[cur-1][0][1] + f[cur-1][1][1]) % MOD;
	if (!cy[y].r && !cy[y].u) f[cur][1][1] = (f[cur-1][0][0] + f[cur-1][1][0]) % MOD;
    } 
    
    for (int x=2;x<=m;x++) {
	cur++;
	
	if (!cx[x].l && !cx[x].u) f[cur][0][1] = (f[cur-1][1][0] + f[cur-1][1][1]) % MOD;
	if (!cx[x].l && !cx[x].d) f[cur][0][0] = (f[cur-1][1][0] + f[cur-1][1][1]) % MOD;
	if (!cx[x].r && !cx[x].d) f[cur][1][0] = (f[cur-1][0][0] + f[cur-1][0][1]) % MOD;
	if (!cx[x].r && !cx[x].u) f[cur][1][1] = (f[cur-1][0][0] + f[cur-1][0][1]) % MOD;
    }
   
    cout << (f[cur][0][0] + f[cur][0][1] + f[cur][1][0] + f[cur][1][1]) % MOD << endl;
   
    return 0;
}