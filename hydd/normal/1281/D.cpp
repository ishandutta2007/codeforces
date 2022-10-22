#include<cstdio>
using namespace std;
int T,n,m;
bool a[71][71];
char s[71];
void work(){
	bool flag;
	//case1:ans=0
	flag=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			flag=flag&&a[i][j];
	if (flag){ puts("0"); return;}
	//case2:ans=MORTAL
	flag=false;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			flag=flag||a[i][j];
	if (!flag){ puts("MORTAL"); return;}
	//case3:ans=1
	flag=true;
	for (int i=1;i<=m;i++) flag=flag&&a[1][i];
	if (flag){ puts("1"); return;}
	flag=true;
	for (int i=1;i<=m;i++) flag=flag&&a[n][i];
	if (flag){ puts("1"); return;}
	flag=true;
	for (int i=1;i<=n;i++) flag=flag&&a[i][1];
	if (flag){ puts("1"); return;}
	flag=true;
	for (int i=1;i<=n;i++) flag=flag&&a[i][m];
	if (flag){ puts("1"); return;}
	//case4:ans=2
	if (a[1][1]||a[1][m]||a[n][1]||a[n][m]){ puts("2"); return;}
	for (int i=1;i<=n;i++){
		flag=true;
		for (int j=1;j<=m;j++)
			flag=flag&&a[i][j];
		if (flag){ puts("2"); return;}
	}
	for (int i=1;i<=m;i++){
		flag=true;
		for (int j=1;j<=n;j++)
			flag=flag&&a[j][i];
		if (flag){ puts("2"); return;}
	}
	//case5:ans=3
	flag=false;
	for (int i=1;i<=m;i++) flag=flag||a[1][i];
	if (flag){ puts("3"); return;}
	flag=false;
	for (int i=1;i<=m;i++) flag=flag||a[n][i];
	if (flag){ puts("3"); return;}
	flag=false;
	for (int i=1;i<=n;i++) flag=flag||a[i][1];
	if (flag){ puts("3"); return;}
	flag=false;
	for (int i=1;i<=n;i++) flag=flag||a[i][m];
	if (flag){ puts("3"); return;}
	puts("4");
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++){
			scanf("%s",s+1);
			for (int j=1;j<=m;j++)
				if (s[j]=='A') a[i][j]=true;
				else a[i][j]=false;
		}
		work();
	}
	return 0;
}