#include<bits/stdc++.h>
using namespace std;
typedef double db;
db ans=1;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(k>=m)printf("1\n");
	else if(n+k<m)printf("0\n");
	else{
		for(int i=1;i<=k+1;i++)ans=ans*(m-i+1)/(n+i);
		ans=1.0-ans;
		printf("%.6lf",ans);
	}
	return 0;
}