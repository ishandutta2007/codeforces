#include<bits/stdc++.h>
#define MAX    333
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int n;
char a[MAX];
set<char> x,y;
int main(void) {
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",a);
		REP(j,n) if (i==j || i+j==n-1) x.insert(a[j]); else y.insert(a[j]);		
	}
	if (x.size()==1 && y.size()==1 && *x.begin()!=*y.begin()) printf("YES"); else printf("NO");
	return 0;
}