#include<cstdio>
#include<vector>
#define MAX   1010
using namespace std;
bool a[MAX];
int p[MAX];
int up[MAX];
int pos,n;
vector<int> v;
vector<int> val;
int find(int x) {
	if (up[x]<0) return (x);
	up[x]=find(up[x]);
	return (up[x]);
}
void join(int a,int b) {
	int x=find(a);
	int y=find(b);
	if (x==y) return;
	up[x]=up[x]+up[y];
	up[y]=x;
}
void init(void) {
	int i,j,k;
	scanf("%d",&n);
	scanf("%d",&k);	
	for (i=1;i<=n;i=i+1) up[i]=-1;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&p[i]);
		if (p[i]!=0) join(p[i],i);		
	}
	pos=1;	
	j=k;
	while (up[j]>0) {
		pos++;
		j=p[j];
	}	
	val.clear();
	for (i=1;i<=n;i=i+1)
		if ((up[i]<0) && (find(k)!=i)) val.push_back(-up[i]);
}
void process(void) {
	int i,j,k;
	for (i=1;i<=1000;i=i+1) a[i]=false;
	a[0]=true;
	v.clear();
	v.push_back(0);	
	for (i=0;i<val.size();i=i+1) {
		k=v.size();
		for (j=0;j<k;j=j+1) {
			if (val[i]+v[j]>1000) continue;
			if (!a[val[i]+v[j]]) {
				a[val[i]+v[j]]=true;
				v.push_back(val[i]+v[j]);
			}
		}			
	}
	for (i=0;i<=1000;i=i+1)
		if (a[i]) printf("%d\n",i+pos);
}
int main(void) {
	init();
	process();
	return 0;
}