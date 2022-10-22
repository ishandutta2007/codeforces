#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	
	int tmp=n-1,ans=0;
	while (tmp) tmp/=k,ans++;
	printf("%d\n",ans);

	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++){
			int u=i,v=j,c=0;
			while (u!=v) u/=k,v/=k,c++;
			printf("%d ",c);
		}
	return 0;
}