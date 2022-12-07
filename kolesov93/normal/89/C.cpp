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
int n,m;
#define N 5555
int l[N],r[N],d[N],u[N];
int L[N],R[N],D[N],U[N];
char c[N];

int gt(int x, int y) {
    return y*m + x;
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    vector<int> cand;
    
    cin >> n >> m;
    int num = 0;
    for (int i=0;i<n;i++) {
	for (int j=0;j<m;j++) {
	    char C = getchar();
	    while (C != 'L' && C != 'R' && C != 'D' && C != 'U' && C != '.') C = getchar();
	    c[num++] = C;
	    if (C != '.') cand.push_back(num-1);
	}
    }
    
    memset(u,-1,sizeof(u));
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    memset(d,-1,sizeof(d));
    for (int y=0;y<n;y++)
	for (int x=0;x<m;x++) {
	    num = gt(x,y);
	    if (y > 0) {
		if (c[gt(x,y-1)] != '.') u[num] = gt(x,y-1);
		else u[num] = u[gt(x,y-1)];
	    }
	    if (x > 0) {
		if (c[gt(x-1,y)] != '.') l[num] = gt(x-1,y);
		else l[num] = l[gt(x-1,y)];
	    }
	}
    for (int y=n-1;y>=0;y--)
	for (int x=m-1;x>=0;x--) {
	    num = gt(x,y);
	    if (y < n-1) {
		if (c[gt(x,y+1)] != '.') d[num] = gt(x,y+1);
		else d[num] = d[gt(x,y+1)];
	    }
	    if (x < m-1) {
		if (c[gt(x+1,y)] != '.') r[num] = gt(x+1,y);
		else r[num] = r[gt(x+1,y)];
	    }
	}
	
    int best = 0, cnt = 0;
    for (int t=0;t<cand.size();t++) {
	memcpy(L,l,sizeof(l));
	memcpy(R,r,sizeof(r));
	memcpy(U,u,sizeof(u));
	memcpy(D,d,sizeof(d));
	
	num = cand[t];
	int score = 0;
	while (num != -1) {
	    score++;
	    int nxt;
	    if (c[num] == 'L') nxt = L[num];
	    if (c[num] == 'R') nxt = R[num];
	    if (c[num] == 'U') nxt = U[num];
	    if (c[num] == 'D') nxt = D[num];
	    
	    if (L[num] != -1) R[ L[num] ] = R[num];
	    if (R[num] != -1) L[ R[num] ] = L[num];
	    if (U[num] != -1) D[ U[num] ] = D[num];
	    if (D[num] != -1) U[ D[num] ] = U[num];
	    
	    num = nxt;
	}
	
	if (score > best) {
	    best = score;
	    cnt = 0;
	}
	if (score == best) cnt++;
    }
    
    cout << best << " " << cnt << endl;
    
    return 0;
}