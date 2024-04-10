#include<bits/stdc++.h>
#define MAX   1111
using namespace std;
char s[MAX];
vector<int> v;
int n;
void process(void) {
	scanf("%s",s);
	n=strlen(s);
	int i;
	v.clear();
	for (i=0;i<n;i=i+1)
		if (i%2==0) v.push_back(s[i]-48);
	sort(v.begin(),v.end());
	for (i=0;i<(int)v.size()-1;i=i+1)
		printf("%d+",v[i]);
	printf("%d",v[v.size()-1]);
}
int main(void) {
	process();
	return 0;
}