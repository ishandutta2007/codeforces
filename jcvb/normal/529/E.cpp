#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
void gn(int &x){
	char c;while((c=getchar())<'0'||c>'9');x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
}
int n,k;
int a[5005];
map<int,int>ma;
#define inf 1000000000
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++){
			int su=a[i]*j;
			ma[su]=j;
		}
	int q;scanf("%d",&q);
	while(q--){
		int mi=inf;
		int x;scanf("%d",&x);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=k;j++){
				int lef=x-a[i]*j;
				if(lef==0){
					mi=min(mi,j);
				}else if(lef<0)continue;
				else{
					if(ma.find(lef)!=ma.end())
						mi=min(mi,j+ma[lef]);
				}
			}
		if(mi>k)printf("-1\n");
		else printf("%d\n",mi);
	}
	return 0;
}