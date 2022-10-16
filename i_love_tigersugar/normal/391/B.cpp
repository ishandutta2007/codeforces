#include<bits/stdc++.h>
#define MAX   1111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
char a[MAX];
vector<int> v[33];
int value(vector<int> &v,int p) {
	int ret=0;
	int i=0;
	while (true) {
		while (i<v.size() && v[i]%2!=p) i++;
		if (i>=v.size()) return (ret);
		ret++;
		p=1-p;
	}
}
void process(void) {
	scanf("%s",a);
	int n=strlen(a);
	REP(i,n) v[a[i]-'A'].push_back(i);
	int res=0;
	REP(i,26) REP(j,2) res=max(res,value(v[i],j));
	printf("%d",res);
}
int main(void) {
	process();
	return 0;
}