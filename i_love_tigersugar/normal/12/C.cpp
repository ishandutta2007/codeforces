#include<bits/stdc++.h>
#define MAX   111
using namespace std;
struct fruit {
	char name[37];
	int exist;
	fruit(){}
	void assign(const char s[]) {
		int l=strlen(s);
		int i;
		for (i=0;i<=l;i=i+1) name[i]=s[i];
		exist=1;
	}
	bool equal(const char s[]) const {
		return (strcmp(name,s)==0);
	}
	bool operator < (const fruit &x) const {
		return (exist>x.exist);
	}
};
fruit lst[MAX];
int price[MAX];
int m,n,p;
void init(void) {
	char tmp[37];
	scanf("%d",&n);
	scanf("%d",&m);
	int i,j;
	bool diff;
	p=0;
	for (i=1;i<=n;i=i+1) scanf("%d",&price[i]);
	for (i=1;i<=m;i=i+1) {
		scanf("%s",tmp);
		diff=true;
		for (j=1;j<=p;j=j+1)
			if (lst[j].equal(tmp)) {
				diff=false;
				lst[j].exist++;
				break;
			}
		if (diff) {
			p++;
			lst[p].assign(tmp);
		}
	}
	sort(&lst[1],&lst[p+1]);
	sort(&price[1],&price[n+1]);
	int minval=0;
	int maxval=0;
	for (i=1;i<=p;i=i+1) {
		minval+=lst[i].exist*price[i];
		maxval+=lst[i].exist*price[n+1-i];
	}
	printf("%d %d",minval,maxval);
}
int main(void) {
	init();
	return 0;
}