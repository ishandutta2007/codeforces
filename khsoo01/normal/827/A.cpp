#include<bits/stdc++.h>
using namespace std;
const int M = 2000005;

int n, par[M], mx;
char ipt[M], str[M];

int Find (int X) {return par[X] = (par[X] == X ? X : Find(par[X]));}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<M;i++) par[i] = i;
	for(int i=1;i<=n;i++) {
		int m, t, l;
		scanf("%s%d",ipt,&m);
		l = strlen(ipt);
		while(m--) {
			scanf("%d",&t);
			for(int j=Find(t);j<t+l;j=Find(j)) {
				str[j] = ipt[j-t];
				mx = max(mx, j);
				par[j] = j+1;
			}
		}
	}
	for(int i=1;i<=mx;i++) {
		putchar(str[i] ? str[i] : 'a');
	}
	puts("");
}