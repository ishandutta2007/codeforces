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
const ll mod = 1000000007;
#define N 200022
ll s[N];
int n,m,k;
int a[N];
int S[N],F[N];

int prev(int x) {return x&(x-1);}
int next(int x) {return x+x-prev(x);}

void modify(int x, ll val) {
    x++;
    for (;x<=k;x=next(x)) s[x] = (s[x] + val) % mod;
}

ll findsum(int l, int r) {
    if (l > r) return 0;
    
    ll ans = 0;
    r++;
    
    while (r) {
	ans += s[r];
	r = prev(r);
    }
    
    while (l) {
	ans = (ans + mod - s[l]) % mod;
 	l = prev(l);
    }
    
    return ans;
}

vector<int> g[N];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d",&n,&m);
    a[0] = 0; a[1] = n;
    k = 2;
    
    for (int i=0;i<m;i++) {
	scanf("%d%d",&S[i],&F[i]);
	a[k++] = F[i];
    }
    
    
    sort(a,a+k);
    k = unique(a,a+k) - a;
    
    for (int i=0;i<m;i++) {
	int pos = lower_bound(a,a+k,F[i]) - a;
	g[pos].push_back(i);
    }
    
    modify(0,1);
    
    for (int i=0;i<k;i++) {
	for (int j=0;j<g[i].size();j++) {
	    int pos = lower_bound(a,a+k,S[ g[i][j] ]) - a;
	    while (a[pos] < S[ g[i][j] ]) pos++;
	    ll cur = findsum(pos,i-1);
	    modify(i,cur);
	}
    }
    
    cout << findsum(k-1,k-1) % mod << endl;
    
    return 0;
}