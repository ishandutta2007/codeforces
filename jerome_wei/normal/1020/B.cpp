#include<bits/stdc++.h>
using namespace std;
int n,p[1010];
bool vis[1010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int j=1;j<=n;j++){
	for(int i=1;i<=n;i++)vis[i]=false;
	int cur=j;
	while(!vis[cur]){
	    vis[cur]=true;
	    cur=p[cur];
	}
	printf("%d ",cur);
    }
}