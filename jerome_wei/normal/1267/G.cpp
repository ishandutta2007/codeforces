#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
const int N = 110, M = 10010;
int n;
db x;
int c[N],all;
db binom[N][N];
db f[N][M];

int main()
{
	cin >> n >> x;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),all+=c[i];
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		binom[i][0]=binom[i][i]=1;
		for(int j=1;j<i;j++)binom[i][j]=binom[i-1][j]+binom[i-1][j-1];
	}
	f[0][0]=1;
	for(int id=1;id<=n;id++){
		for(int i=id;i;i--){
			for(int j=all;j>=c[id];j--){
				f[i][j]+=f[i-1][j-c[id]];
			}
		}
	}
	db ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=all;j++){
			db v=f[i][j];
			// if(v>0)cout << i << ":" << j << " " << v << endl;
			v/=binom[n][i];
			v*=min(x/2+x/2*n/i, (db)j/(db)i);
			ans+=v;
		}
	}
	printf("%.15Lf\n",ans);
}