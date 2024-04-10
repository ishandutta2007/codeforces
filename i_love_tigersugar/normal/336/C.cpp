#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
vector<int> v[41];
int a[MAX];
int b[MAX][41];
int s[41];
int x[41];
int n;
int best,bc;
bool res[MAX];
void init(void) {
	scanf("%d",&n);
	int i;
	int tmp;
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
	tmp=a[1];
	for (i=2;i<=n;i=i+1) tmp=tmp&a[i];
	if (tmp>0) {
		printf("%d\n%d",n,a[1]);
		for (i=2;i<=n;i=i+1) printf(" %d",a[i]);
		exit(0);
	}
}
void construct(void) {	
	int i,j;
	for (i=0;i<31;i=i+1) {
		v[i].clear();
		s[i]=0;
	}
	for (i=1;i<=n;i=i+1)
		for (j=0;j<31;j=j+1) {
			b[i][j]=((a[i]|(1<<j))==a[i]);
			if (b[i][j]==0) v[j].push_back(i);
			s[j]+=b[i][j];
		}	
}
void process(void) {
	int i,j,k;
	for (i=0;i<31;i=i+1) {
		for (j=0;j<31;j=j+1) x[j]=s[j];
		for (j=0;j<v[i].size();j=j+1)
			for (k=0;k<31;k=k+1)
				x[k]-=b[v[i][j]][k];
		for (k=0;k<31;k=k+1)
			if (x[k]==n-(int)v[i].size()) {
				if (best<k) {
					best=k;
					bc=i;
				}
				break;
			}
	}
	for (i=1;i<=n;i=i+1) res[i]=true;
	for (i=0;i<v[bc].size();i=i+1) res[v[bc][i]]=false;
	printf("%d\n",n-(int)v[bc].size());
	bool fst=true;
	for (i=1;i<=n;i=i+1)
		if (res[i]) {
			if (!fst) printf(" ");
			printf("%d",a[i]);			
			fst=false;
		}
}
int main(void) {
	init();
	construct();
	process();
	return 0;
}