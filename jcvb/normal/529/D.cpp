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

int n,M,len;
int a[20005];
int qu[20005];int p=0,q=0;
int ans[20005],tot=0;
int main()
{
	scanf("%d%d%d",&n,&M,&len);
	for (int i=1;i<=n;i++){
		int h,m,s;
		gn(h);gn(m);gn(s);
		a[i]=h*60*60+m*60+s;
	}
	int ma=0;
	for (int i=1;i<=n;i++){
		while(p!= q&& qu[p]<a[i])p++;
		if(q-p>=M){
			q--;
			qu[q++]=a[i]+len-1;
			ans[i]=tot;
		}else{
			qu[q++]=a[i]+len-1;
			ans[i]=++tot;
		}
		ma=max(ma,q-p);
	}
	if(ma!=M)printf("No solution\n");
	else{
		printf("%d\n",tot);
		for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
	}
	return 0;
}