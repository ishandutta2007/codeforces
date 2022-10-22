#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
char mp[100][100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='#'){
				for(int k=1;k<=n;k++)
					if(mp[k][j]=='#'){
						for(int l=1;l<=m;l++)
							if(mp[k][l]!=mp[i][l]){
								printf("No\n");return 0;
							}
					}
			}
		}
	}
	printf("Yes\n");
	return 0;
}