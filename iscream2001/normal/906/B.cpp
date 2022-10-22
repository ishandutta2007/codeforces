#include<bits/stdc++.h>
#define maxn 100000
using namespace std;

int a[maxn+10];
int n,m;

int xx[]={1,0,-1,0};
int yy[]={0,1,0,-1};

bool beside(int a,int b){
	if(a+m==b||a-m==b||a+1==b||a-1==b) return 1;
	return 0;
}//

bool flag;

void dfs(int p){
	if(p==n*m){
		flag=1;return;
	}
	int xp=p/m;
	int yp=p%m;
	for(int i=p;i<n*m;++i){
		swap(a[p],a[i]);
		if((xp&&beside(a[p],a[(xp-1)*m+yp]))||(yp&&beside(a[p],a[xp*m+yp-1])))
		 continue;
		dfs(p+1);
		if(flag) return;
		swap(a[p],a[i]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=0;i<n*m;++i) a[i]=i;
	dfs(0);
	if(flag){
		printf("YES\n");
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
			 printf("%d ",a[i*m+j]+1);
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}