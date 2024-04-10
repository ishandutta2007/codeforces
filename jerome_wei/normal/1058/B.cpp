#include<bits/stdc++.h>
using namespace std;

int n,d;
int f[110][110];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)if((i<n-d&&j>i+d)||(i<d&&j+i<d)||(i>d&&j<i-d)||(i>n-d&&j>n*2-d-i))
			f[i][j]=1;
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)printf("%d ",f[i][j]);
		cout<<endl;
	}*/
	int m;
	scanf("%d",&m);
	while(m--){
		int x,y;
		cin>>x>>y;
		if(f[x][y])printf("NO\n");
		else printf("YES\n");
	}
}