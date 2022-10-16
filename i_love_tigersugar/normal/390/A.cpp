#include<bits/stdc++.h>
#define MAX   111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
bool ex[MAX],ey[MAX];
int main(void) {
	int n;
	int cx=0;
	int cy=0;
	scanf("%d",&n);
	REP(i,n) {
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		if (!ex[x]) {
			cx++;
			ex[x]=true;
		}
		if (!ey[y]) {
			cy++;
			ey[y]=true;
		}
	}
	printf("%d",min(cx,cy));
	return 0;
}