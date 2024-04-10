#include<bits/stdc++.h>
using namespace std;

int query(int x1,int y1,int x2,int y2){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	fflush(stdout);
	int ret;cin >> ret;
	return ret;
}
const int N = 111;
int ans[N][N],n;

int col[N][N];
int present;
int g(int x,int y){
	return (x+y)%2==0?ans[x][y]:(col[x][y]^present);
}
inline void answer(){
	cout << "!" << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout << g(i,j);
		puts("");
	}
	exit(0);
}

inline void cal(int x,int y,int x2,int y2){
	int d=x2-x;
	for(int i=0;i<1<<3;i++)if(__builtin_popcount(i)==d){
		int d1=1&(x>>0),d3=1&(x>>2);
		int nx1=x,nx2=x2,ny1=y,ny2=y2;
		if(d1){
			nx1++;
		}else ny1++;
		if(d3)nx2--;
		else ny2--;
		if((g(x,y)^g(nx2,ny2))==((g(x2,y2)^g(nx1,ny1)))){
			int ans=query(x,y,x2,y2);
			present=ans^(g(x,y)^g(x2,y2))^1;
			answer();
		}
	}
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]=-1;
	ans[1][1]=1;ans[n][n]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ans[i][j]==-1){
		if((i+j)%2==0){
			if(i==1)ans[i][j]=query(i,j-2,i,j)^ans[i][j-2]^1;
			else if(j==1)ans[i][j]=query(i-2,j,i,j)^ans[i-2][j]^1;
			else{
				ans[i][j]=query(i-1,j-1,i,j)^ans[i-1][j-1]^1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=2;j<=n-2;j+=2){
				col[i][j+2]=col[i][j]^1^query(i,j,i,j+2);
			}
			if(i<n)col[i+1][n]=col[i][n-1]^1^query(i,n-1,i+1,n);
		}else{
			for(int j=n-2;j>0;j-=2){
				col[i][j]=col[i][j+2]^1^query(i,j,i,j+2);
			}
			if(i<n)col[i+1][2]=col[i][1]^1^query(i,1,i+1,2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+2<=n&&j+1<=n){
				cal(i,j,i+2,j+1);
			}
			if(i+1<=n&&j+2<=n){
				cal(i,j,i+1,j+2);
			}
		}
	}
}