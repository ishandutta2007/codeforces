#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

unsigned f[N][N];
bool vis[N][N];
int n,p,q;
unsigned int __g[N];
unsigned int bin[150][150],BIN[N];
inline void init(int _n=1000){
	bin[0][0]=1;
	for(int i=1;i<=140;i++){
		// cout << i << endl;
		bin[i][0]=1;
		for(int j=1;j<=min(i,133);j++)bin[i][j] = bin[i-1][j] + bin[i-1][j-1];
	}
	// return;
	BIN[0]=1;
	for(int i=1;i<=min(150,n);i++){
		__g[i]=n-i+1;
		// for(int j=1;j<=i;j++)cout << __g[i] << " ";puts("");
		int v=i;
		for(int j=1;j<=i;j++){
			int g=__gcd((int)__g[j],(int)v);
			v/=g,__g[j]/=g;
		}
		// cout << i << ":" << v << endl;
		BIN[i]=1;
		for(int j=1;j<=i;j++){
			BIN[i]*=__g[j];
		}
		// cout << i << " " << BIN[i] << endl;
	}
}

inline unsigned int solve(int i,int j){
	// cout << i << " " << j << endl;
	if(i==0 && j==0)return 1;
	if(j==0 && i > 0)return 0;
	if(vis[i][j])return f[i][j];
	for(int k=1;k<=i;k++){
		f[i][j]+=solve(i-k,j-1)*bin[i][k];
	}
	vis[i][j] = 1;
	return f[i][j];
}
unsigned int g[N][N],G[N];

int main()
{
	cin >> n >> p >> q;
	init();
	p=min(p,n);
	unsigned ans=0;
	// cout << p << endl;
	for(int i=0;i<=p;i++){
		for(int j=0;j<=i;j++){
			if(i>=n)continue;
			g[i][j] = solve(i,j);//
			// cout << i << " " << j << " " << g[i][j] << " " << g[i][j]*BIN[i] << endl;
			g[i][j]*=BIN[i];
			G[j]+=g[i][j];
		}
	}
	memset(bin,0,sizeof(bin));
	bin[0][0]=1;
	for(int i=1;i<=q;i++){
		bin[i%2][0]=1;
		for(int j=1;j<=min(i,133);j++)bin[i%2][j] = bin[(i-1)%2][j] + bin[(i-1)%2][j-1];
		// cout << i << "!" << endl;
		unsigned h = 0;
		for(int j=0;j<=p;j++){
			// cout << G[j] << endl;
			h+=bin[i%2][j]*G[j];
		}
		// cout << h << endl;
		// cout << solve(n,i) << endl;
		ans^=(unsigned)i*h;
	}
	cout << ans << endl;
}