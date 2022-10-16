#include<bits/stdc++.h>
#define MAX   111
const char insf[]="NULL";
const char delf[]="ILLEGAL_ERASE_ARGUMENT";
int mem[MAX];
int t,c,n;
void init(void) {
	scanf("%d",&t);
	scanf("%d",&n);
	c=0;
	memset(mem,0,sizeof mem);
}
int alloc(const int &s) {
	int i,j;
	bool fr;
	for (i=1;i+s-1<=n;i=i+1) {
		fr=true;
		for (j=i;j<=i+s-1;j=j+1)
			if (mem[j]>0) {
				fr=false;
				break;
			}
		if (fr) {
			c++;			
			for (j=i;j<=i+s-1;j=j+1) mem[j]=c;
			return (c);
		}
	}
	return (0);
}
bool erase(const int &x) {	
	if (x<1) return (false);
	int i;
	bool ret=false;
	for (i=1;i<=n;i=i+1)
		if (mem[i]==x) {
			mem[i]=0;
			ret=true;
		}
	return (ret);
}
void defragment(void) {
	int b[MAX];
	memset(b,0,sizeof b);
	int i;
	int j=0;
	for (i=1;i<=n;i=i+1)
		if (mem[i]>0) {
			j++;
			b[j]=mem[i];
		}
	memset(mem,0,sizeof mem);
	for (i=1;i<=n;i=i+1) mem[i]=b[i];
}
void process(void) {
	char cmd[MAX];
	int i,x;
	for (i=1;i<=t;i=i+1) {
		scanf("%s",cmd);
		if (cmd[0]=='a') {
			scanf("%d",&x);
			if (alloc(x)>0) printf("%d\n",c);
			else printf("%s\n",insf);
		}
		if (cmd[0]=='e') {
			scanf("%d",&x);
			if (!erase(x)) printf("%s\n",delf);
		}
		if (cmd[0]=='d') defragment();
	}
}
int main(void) {
	init();
	process();
	return 0;
}