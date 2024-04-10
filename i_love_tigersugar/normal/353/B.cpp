#include<bits/stdc++.h>
#define MAX   222
using namespace std;
vector<int> c[MAX];
bool e[3][MAX];
int r[MAX];
int n;
int s[3];
void init(void) {
	scanf("%d",&n);
	int i,t;
	for (i=1;i<=2*n;i=i+1) {
		scanf("%d",&t);
		c[t].push_back(i);	
	}
}
void divide(void) {
	int i,j;
	j=0;
	for (i=10;i<100;i=i+1)
		if (c[i].size()==1) {
			r[c[i][0]]=j;
			s[j]++;
			e[j][i]=true;
			j=(j+1)%2;
			c[i].clear();
		}
	for (i=10;i<100;i=i+1)
		if (c[i].size()>1) {
			r[c[i][c[i].size()-1]]=0;
			c[i].pop_back();
			r[c[i][c[i].size()-1]]=1;
			c[i].pop_back();
			s[0]++;
			s[1]++;
			e[0][i]=true;
			e[1][i]=true;
		}
	for (i=10;i<100;i=i+1)	
		for (j=0;j<c[i].size();j=j+1) {
			if (s[0]<n) {
				s[0]++;
				r[c[i][j]]=0;
				e[0][i]=true;
			}
			else {
				s[1]++;
				r[c[i][j]]=1;
				e[1][i]=true;
			}
		}
	assert(s[0]==n && s[1]==n);
	int d1=0;
	int d2=0;
	for (i=10;i<100;i=i+1) {
		if (e[0][i]) d1++;
		if (e[1][i]) d2++;		
	}
	printf("%d\n",d1*d2);
	for (i=1;i<=2*n;i=i+1) printf("%d ",r[i]+1);
}
int main(void) {
	init();
	divide();
	return 0;
}