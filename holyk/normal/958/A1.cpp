#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=20;
char a[N][N],b[N][N];
int main(){
	int n=read();
	for (int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for (int i=1;i<=n;++i) scanf("%s",b[i]+1);
	bool gfg;
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (a[i][j]!=b[i][j]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=j,y=n-i+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-i+1,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-j+1,y=i;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=i,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
	for (int i=1;i<=(n>>1);++i){
		for (int j=1;j<=n;++j){
			swap(a[i][j],a[n-i+1][j]);
		}
	}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (a[i][j]!=b[i][j]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=j,y=n-i+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-i+1,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-j+1,y=i;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=i,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
	for (int i=1;i<=(n>>1);++i){
		for (int j=1;j<=n;++j){
			swap(a[i][j],a[n-i+1][j]);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=(n>>1);++j){
			swap(a[i][j],a[n-i+1][j]);
		}
	}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (a[i][j]!=b[i][j]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=j,y=n-i+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-i+1,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-j+1,y=i;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=i,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
	for (int i=1;i<=(n>>1);++i){
		for (int j=1;j<=n;++j){
			swap(a[i][j],a[n-i+1][j]);
		}
	}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (a[i][j]!=b[i][j]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=j,y=n-i+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-i+1,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=n-j+1,y=i;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
		gfg=1;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				int x=i,y=n-j+1;
				if (a[i][j]!=b[x][y]){
					gfg=0;
					break;
				}
			}
			if (!gfg) break;
		}
		if (gfg){
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}