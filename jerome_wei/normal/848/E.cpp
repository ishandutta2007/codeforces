#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */

typedef vector<int> poly;
namespace Template_Poly{
	int rev[2000010];
	void Mul(poly &tar,poly a,poly b){
		tar.resize(a.size());
		for(size_t i=0;i<a.size();i++){
			tar[i]=add(tar[i], mul(a[i],b[i]));
		}
	}
	void DFT(int *t,int n,int type){
		int l=0;while(1<<l<n)++l;
		for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<n;i++)if(rev[i]>i)swap(t[rev[i]],t[i]);
		for(int step=1;step<n;step<<=1){
			int wn=qpow(3,(mod-1)/(step<<1));
			for(int i=0;i<n;i+=step<<1){
				int w=1;
				for(int k=0;k<step;k++,w=mul(w,wn)){
					int x=t[i+k],y=mul(t[i+k+step],w);
					t[i+k]=add(x,y),t[i+k+step]=sub(x,y);
				}
			}
		}
		if(type==1)return;
		for(int i=1;i<n-i;i++)swap(t[i],t[n-i]);
		int inv=qpow(n,mod-2);
		for(int i=0;i<n;i++)t[i]=mul(t[i],inv);
	}
	poly NTT(poly A,int n,poly B,int m){
		static poly res,PolA,PolB;
		PolA=A,PolB=B;
		int len=1;while(len < n+m)len<<=1;
		res.resize(len);
		PolA.resize(len),PolB.resize(len);
		DFT(&PolA[0],len,1);DFT(&PolB[0],len,1);
		for(int i=0;i<len;i++) res[i]= mul(PolA[i],PolB[i]);
		DFT(&res[0],len,-1);
		res.resize(n+m-1);
		return res;
	}
	poly NTT(poly A,poly B){
		return NTT(A,A.size(),B,B.size());
	}
}
using namespace Template_Poly;
const int N = 1e5+5;
int n;
int f[2][2][N];
int g[2][2][N],t[N];
inline void init(int n){
	t[0]=1;for(int i=1;i<=n;i++)t[i] = add(i>1?t[i-2]:0,i>=4?t[i-4]:0);
	// cout << t[0] << " " << t[1] << " " << t[2] << endl;
	for(int i=1;i<=n;i++){
		for(int sta=0;sta<2;sta++)for(int stb=0;stb<2;stb++){
			g[sta][stb][i+1] = mul(i,i);
			int len1 = i-(sta&1)-(stb&1);
			if(len1<0)g[sta][stb][i+1]=0;
			else g[sta][stb][i+1]=mul(g[sta][stb][i+1], mul(t[len1],1));
			// cout << i+1 << " " << sta << " " << stb << "::" << len1 << ":" << g[sta][stb][i+1] << endl;
		}
	}
	//g[i] : len = i-1 with a new divide
}

inline void solve(int l,int r){
	// if(l==r){
	// 	cout << l << ":" << endl;for(int i=0;i<2;i++)for(int j=0;j<2;j++)cout << i << " " << j << ":" << f[i][j][l] << endl;
	// }
	if(l==r)return ;
	int mid = (l+r)>>1;
	solve(l,mid);
	// cerr << l << " to " << r << "::" << endl;
	int len = 1;while(len<2*(r-l+1))len<<=1;
	poly p[2][2];
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			p[a][b] = vector<int> (g[a][b]+0, g[a][b]+r-l+1+1);
			p[a][b].resize(len);
			DFT(&p[a][b][0], len, 1);
		}
	}
	poly ans[2][2];
	for(int st=0;st<2;st++){
		for(int sta=0;sta<2;sta++){
			poly p2 = vector<int> (f[st][sta]+l, f[st][sta]+mid+1);
			p2.resize(len);
			DFT(&p2[0],len,1);
			for(int tar=0;tar<2;tar++) Mul(ans[st][tar], p2, p[sta][tar]);
		}
	}
	int l2=mid-l+1;
	for(int sta=0;sta<2;sta++){
		for(int stb=0;stb<2;stb++){
			DFT(&ans[sta][stb][0],len,-1);
			// cout << sta << " " << stb << ":" << endl;
			// for(int k=0;k<len;k++)cout << ans[sta][stb][k] << " ";puts("");
			for(int id=mid+1,t=l2;id<=r;t++,id++){
				f[sta][stb][id]=add(f[sta][stb][id],ans[sta][stb][t]);
			}
		}
	}
	solve(mid+1,r);
}

int main()
{
	cin >> n;
	if(n<=2){puts("0");return 0;}
	init(n*2);
	for(int i=2;i<=n;i++){//calculate the one include '1'
		for(int sta=0;sta<2;sta++)for(int stb=0;stb<2;stb++){
			f[sta][stb][i] = mul(g[sta][stb][i],i);
			// cout << i << " " << sta << " " << stb << ":" << f[sta][stb][i] << " " <<  g[sta][stb][i] << endl;
		}
	}
	solve(1,n);
	int ans = 0;
	// 
	
	for(int sta=0;sta<2;sta++){
		int nxt = sta;
		ans = add(ans, f[sta][nxt][n]);
	}
	cout << ans << endl;
}