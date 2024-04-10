#include<bits/stdc++.h>
#define ft forward_as_tuple
#define tup tuple<ll,int,int>
#define rgi register int
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=1010;
ll n,m,A,B;
ll a[N][N],sum[N][N];
int p[N][N][12],vis[N][N];
vector<tup>v,ans;
inline ll qry(int w,int l,int r){
	int k=log2(r-l+1);
	return min(p[w][l][k],p[w][r-(1<<k)+1][k]);
}
inline ll su(int x,int y){
	return sum[x+A-1][y+B-1]-sum[x+A-1][y-1]-sum[x-1][y+B-1]+sum[x-1][y-1];
}
multiset<int>s;
signed main(){
	read(n,m,A,B);
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=m;++j){
			read(a[i][j]),p[i][j][0]=a[i][j];
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
		}
	}
	for(rgi i=1;i<=n;++i){
		for(rgi w=1;w<=10;++w){
			for(rgi j=1;j<=m;++j)p[i][j][w]=min(p[i][j][w-1],p[i][j+(1<<w-1)][w-1]);
		}
	}
	for(rgi j=1;j+B-1<=m;++j){
		s.clear();
		for(rgi i=1;i<=A;++i){
			s.insert(qry(i,j,j+B-1));
		}
		
		ll rs=su(1,j)-A*B*(*s.begin());
		v.push_back(ft(rs,1,j));
		for(rgi i=2;i+A-1<=n;++i){
			s.insert(qry(i+A-1,j,j+B-1));
			s.erase(s.find(qry(i-1,j,j+B-1)));
			ll rs=su(i,j)-A*B*(*s.begin());
			v.push_back(ft(rs,i,j));
		}
	}
	sort(v.begin(),v.end());
	for(auto k:v){
		int x=get<1>(k),y=get<2>(k);
		if(!vis[x][y]){
			ans.push_back(k);
			for(rgi i=max(x-A+1,1ll);i<=n&&i<=x+A-1;++i){
				for(rgi j=max(y-B+1,1ll);j<=m&&j<=y+B-1;++j)vis[i][j]=1;
			}
		}
	}
	write(ans.size(),'\n');
	for(auto k:ans)write(get<1>(k),' ',get<2>(k),' ',get<0>(k),'\n');
	
	return 0;
}