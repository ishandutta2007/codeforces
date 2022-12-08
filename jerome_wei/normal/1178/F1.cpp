#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N=1010;
int n,m,c[1000010];
int ls[N],rs[N];
int Min[N][N];
int f[N][N], g[N][N];
int main()
{
	cin >> n >> m;
	int cap=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
		if(i==1||c[i]!=c[i-1])c[++cap]=c[i];
	}
	m=cap;
	if(m>n*2+1){
		puts("0");return 0;
	}
	for(int i=1;i<=m;i++){
		if(!ls[c[i]])ls[c[i]]=i;
		rs[c[i]]=i;
		Min[i][i]=c[i];
		for(int j=i+1;j<=m;j++)Min[i][j]=min(Min[i][j-1],c[j]);
	}
	for(int len=1;len<=m;++len){
		for(int l=1;l+len-1<=m;l++){
			int r=l+len-1;
			int id=Min[l][r];
			if(ls[id] >= l && rs[id] <= r){
				f[l][r]=1;
				int pst=l;
				for(int i=l;i<=r;i++){
					if(c[i]==id){
						if(pst <= i-1)f[l][r]=mul(f[l][r], g[pst][i-1]);
						pst=i+1;
					}
				}
				if(pst <= r)f[l][r]=mul(f[l][r],g[pst][r]);
			}
		}
		for(int l=1;l+len-1<=m;l++){
			int r=l+len-1;
			// cout << l << " " << r << " " << f[l][r] << " ";
			g[l][r]=f[l][r];
			for(int k=l;k<r;k++){
				g[l][r]=add(g[l][r], mul(f[l][k],g[k+1][r]));
			}
			// cout << g[l][r] << endl;
		}
	}
	cout << g[1][m] << endl;
}