#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
const int N=2050,D=998244353;
int C[2*N][2*N],F[N][N];

int main(){
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	for(int i=0;i<2*N;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%D;
	}
	for(int x=0;x<N;++x)
	for(int y=0;y<N;++y)
		F[x][y]=C[x+y][y];

	int n,m;
	cin>>n>>m;
	s64 ans=0;
	for(int c=1;c<m;++c){
		s64 sum=0;
		for(int r=2;r<=n;++r){
			(sum+=(s64)F[n-(r-1)][m-(c+1)]*F[r-1-1][m+1-(c+1)])%=D;
			(ans+=sum*F[n-r][c]%D*F[r-1][c-1])%=D;
		}
	}
	swap(n,m);
	for(int c=1;c<m;++c){
		s64 sum=0;
		for(int r=3;r<=n;++r){
			(sum+=(s64)F[n-(r-2)][m-(c+1)]*F[r-2-1][m+1-(c+1)])%=D;
			(ans+=sum*F[n-r][c]%D*F[r-1][c-1])%=D;
		}
	}
	cout<<ans*2%D<<endl;
}