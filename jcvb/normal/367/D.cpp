#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,d;
int a[200000];
int tms[20]={0};int cur;
void add(int x){
	if(tms[x]==0)cur^=1<<x;
	tms[x]++;
}
void del(int x){
	tms[x]--;
	if(tms[x]==0)cur^=1<<x;
}
int no[100005];int tot=0;	
int label[1<<20];
int cnt(int x){
	int de=0;
	while(x){
		if(x&1)de++;
		x>>=1;
	}
	return de;
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (int i=0;i<m;i++){
		int t;scanf("%d",&t);
		while(t--){
			int x;scanf("%d",&x);
			a[x]=i;
		}
	}
	cur=(1<<m)-1;
	for (int i=1;i<=d;i++)add(a[i]);
	label[cur]=1;
	for (int i=d+1;i<=n;i++){
		add(a[i]);
		del(a[i-d]);
		label[cur]=1;
	}
	int mi=50;
	for (int i=(1<<m)-1;i>=0;i--){
		if(label[i]){
			for (int j=0;j<m;j++)if(i&1<<j){
				label[i^(1<<j)]=1;
			}
		}else mi=min(mi,cnt(i));
	}
	printf("%d\n",mi);
	return 0;
}