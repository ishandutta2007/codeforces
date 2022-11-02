#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 100050

using namespace std;

int n;
long long xs,ys,x2s,y2s;
int x[MAXN],y[MAXN];

inline long long solve() {
	long long sol=0;
	sol=(x2s+y2s)*n-xs*xs-ys*ys;
	return sol;
}

int main(void)
{
	int i;
	while(scanf("%d",&n)==1) {
		xs=ys=0;
		x2s=y2s=0;
		for(i=0;i<n;i++) {
			scanf("%d %d",x+i,y+i);
			xs+=x[i];
			ys+=y[i];
			x2s+=(long long)x[i]*x[i];
			y2s+=(long long)y[i]*y[i];
		}
		cout << solve() << endl;
	}
}