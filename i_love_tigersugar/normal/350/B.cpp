#include<bits/stdc++.h>
#define MAX   100100
int p[MAX];
int l[MAX];
int t[MAX];
int w[MAX];
int n;
void init(void) {
	scanf("%d",&n);
	int i;
	memset(l,0,sizeof l);
	for (i=1;i<=n;i=i+1) scanf("%d",&t[i]);
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&p[i]);
		l[p[i]]++;
	}
}
void process(void) {
	int max=-1;
	int end,len,cur;
	int i;
	for (i=1;i<=n;i=i+1)
		if (t[i]==1) {
			cur=i;
			len=1;
			while (true) {
				if (p[cur]!=0 && l[p[cur]]==1) {
					cur=p[cur];
					len++;
				}
				else {
					if (max<len) {
						max=len;
						end=i;						
					}
					break;
				}
			}
		}
	printf("%d\n",max);
	i=1;
	w[1]=end;
	cur=end;
	while (i<max) {
		i++;
		w[i]=p[cur];
		cur=p[cur];
	}
	for (i=max;i>1;i=i-1) printf("%d ",w[i]);
	printf("%d",w[1]);
}
int main(void) {
	init();
	process();
	return 0;
}