#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int num[400005];int tot;
int n,m;
int lef[200005],rig[200005];
vector<int> go[400005];
int need[200005]={0};
int yes[400005]={0};
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)scanf("%d%d",&lef[i],&rig[i]),rig[i]+=lef[i]-1,num[++tot]=lef[i],num[++tot]=rig[i];
	sort(num+1,num+1+tot);
	tot=unique(num+1,num+1+tot)-num-1;
	for (int i=1;i<=m;i++)lef[i]=lower_bound(num+1,num+1+tot,lef[i])-num,rig[i]=lower_bound(num+1,num+1+tot,rig[i])-num;
	for (int i=1;i<=m;i++)
		go[lef[i]].push_back(i);
	for (int i=1;i<=tot;i++)if(!yes[i] && go[i].size()){
		int st=i,ri=i,j;
		while(1){
			j=0;rig[j]=ri==i?ri-1:ri;
			for (int l=st;l<=(ri==i?ri:(num[ri+1]==num[ri]+1?ri+1:ri));l++){
				yes[l]=1;
				for (int k=0;k<go[l].size();k++)if(rig[go[l][k]]>rig[j])j=go[l][k];
			}
			if(!j)break;
			st=ri+1;
			ri=rig[j];
			need[j]=1;
		}
	}
	int cnt=0;for (int i=1;i<=m;i++)if(!need[i])cnt++;
	printf("%d\n",cnt);
	int fl=0;
	for (int i=1;i<=m;i++)if(!need[i]){
		if(fl)printf(" ");
		else fl=1;
		printf("%d",i);
	}
	printf("\n");
	return 0;
}