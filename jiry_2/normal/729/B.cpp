#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int pd[1100][1100],n,m;
int main(){
	int ans=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&pd[i][j]);
	for (int i=1;i<=n;i++){
		int flag=0;
		for (int j=1;j<=m;j++){
			if (pd[i][j]) flag=1;
			else if (flag) ans++;
		}
		flag=0;
		for (int j=m;j;j--){
			if (pd[i][j]) flag=1;
			else if (flag) ans++;
		}
	}
	for (int i=1;i<=m;i++){
		int flag=0;
		for (int j=1;j<=n;j++){
			if (pd[j][i]) flag=1;
			else if (flag) ans++;
		}
		flag=0;
		for (int j=n;j;j--){
			if (pd[j][i]) flag=1;
			else if (flag) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}