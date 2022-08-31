#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,top,xa,ya;
int a[N][N],b[N][N],st[N<<1];
bool opa[N][N],opb[N][N];
int count(int x,int y){
	int ans=0;
	while(x%y==0){
		x/=y;
		++ans;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x;
			scanf("%d",&x);
			if(x==0){
				a[i][j]=-1;
				b[i][j]=-1;
				xa=i;
				ya=j;
				continue;
			}
			a[i][j]=count(x,2);
			b[i][j]=count(x,5);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]==-1){
				a[i][j]=100000;
			}else if(i==1&&j==1){
				continue;
			}else if(i==1){
				a[i][j]+=a[i][j-1];
			}else if(j==1){
				a[i][j]+=a[i-1][j];
				opa[i][j]=1;
			}else if(a[i-1][j]<a[i][j-1]){
				a[i][j]+=a[i-1][j];
				opa[i][j]=1;
			}else{
				a[i][j]+=a[i][j-1];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(b[i][j]==-1){
				b[i][j]=100000;
			}else if(i==1&&j==1){
				continue;
			}else if(i==1){
				b[i][j]+=b[i][j-1];
			}else if(j==1){
				b[i][j]+=b[i-1][j];
				opb[i][j]=1;
			}else if(b[i-1][j]<b[i][j-1]){
				b[i][j]+=b[i-1][j];
				opb[i][j]=1;
			}else{
				b[i][j]+=b[i][j-1];
			}
		}
	}
	if(min(a[n][n],b[n][n])>1&&xa){
		printf("1\n");
		for(int i=1;i<xa;++i){
			putchar('D');
		}
		for(int i=1;i<ya;++i){
			putchar('R');
		}
		for(int i=xa;i<n;++i){
			putchar('D');
		}
		for(int i=ya;i<n;++i){
			putchar('R');
		}
	}else{
		printf("%d\n",min(a[n][n],b[n][n]));
		if(a[n][n]<b[n][n]){
			for(int i=n,j=n;i!=1||j!=1;){
				if(opa[i][j]){
					--i;
					st[++top]=1;
				}else{
					--j;
					st[++top]=0;
				}
			}
		}else{
			for(int i=n,j=n;i!=1||j!=1;){
				if(opb[i][j]){
					--i;
					st[++top]=1;
				}else{
					--j;
					st[++top]=0;
				}
			}
		}
		while(top){
			putchar(st[top]?'D':'R');
			--top;
		}
	}
	
	return 0;
}