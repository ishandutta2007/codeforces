#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod=1e9+7;
template<int M>
struct modnum{
	int v;
	static int minv(int a,int m){return (a%=m)==1?1:m-ll(minv(m,a))*m/a;}
	modnum():v(0){}
	modnum(ll v_):v(int(v_%M)){if(v<0)v+=M;}
	explicit operator int()const{return v;}
	explicit operator bool()const{return v;}
	friend ostream&operator<<(ostream&out,const modnum&a){return out<<int(a);}
	friend istream&operator>>(istream&in,modnum&a){ll v;in>>v;a=modnum(v);return in;}
	friend bool operator==(const modnum&a,const modnum&b){return a.v==b.v;}
	friend bool operator!=(const modnum&a,const modnum&b){return a.v!=b.v;}
	modnum inv()const{return modnum(minv(v,M));}
	friend modnum inv(const modnum&a){return a.inv();}
	modnum neg()const{return modnum(v?M-v:0);}
	friend modnum neg(const modnum&a){return a.neg();}
	modnum operator-()const{return neg();}
	modnum operator+()const{return *this;}
	modnum&operator++(){if(++v==M)v=0;return*this;}
	modnum&operator--(){if(!v--)v=M-1;return*this;}
	modnum&operator+=(const modnum&a){if((v+=a.v)>=M)v-=M;return*this;}
	modnum&operator-=(const modnum&a){if((v-=a.v)<0)v+=M;return*this;}
	modnum&operator*=(const modnum&a){v=ll(v)*a.v%M;return*this;}
	modnum&operator/=(const modnum&a){return*this*=a.inv();}
	friend modnum operator++(modnum&a,int){modnum r=a;++a;return r;}
	friend modnum operator--(modnum&a,int){modnum r=a;--a;return r;}
	friend modnum operator+(const modnum&a,const modnum&b){return modnum(a)+=b;}
	friend modnum operator-(const modnum&a,const modnum&b){return modnum(a)-=b;}
	friend modnum operator*(const modnum&a,const modnum&b){return modnum(a)*=b;}
	friend modnum operator/(const modnum&a,const modnum&b){return modnum(a)/=b;}
};
using mint = modnum<mod>;

const int N=202,logN=ceil(log2(N))+1;
mint F[2*N],probs[N][N];
int up[N][logN];
int tin[N],tout[N],d[N];
int n,timer;
vector<int>g[N];

void dfs(int u,int p,int depth){
	tin[u]=++timer;
	d[u]=depth;
	up[u][0]=p;
	for(int i=1;i<logN;++i)up[u][i]=up[up[u][i-1]][i-1];
	for(auto v:g[u])if(v!=p)dfs(v,u,depth+1);
	tout[u]=++timer;
}

bool isanc(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v];}

int lca(int u,int v){
	if(isanc(u,v))return u;
	if(isanc(v,u))return v;
	// jumps with u until it barely is the ancestor of v
	for(int i=logN-1;i>=0;--i)
		if(!isanc(up[u][i],v))
			u=up[u][i];
	return up[u][0];
}

mint choose(int n,int k){
	if(k>n||k<0)return 0;
	return F[n]/(F[k]*F[n-k]);
}


mint solve(int root){
	dfs(root,root,0);
	mint res=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<i;++j){
			int lc=lca(i,j);
			int di=d[i]-d[lc];
			int dj=d[j]-d[lc];
			if(di==0){++res;continue;}
			if(dj==0){continue;}
			res+=probs[di][dj];
		}
	return res;
}

void ProGamerMove(){
	F[0]=1;
	for(int i=1;i<2*N;++i)F[i]=F[i-1]*i;
	mint one=1;
	for(int i=1;i<N;++i){
		one/=2;
		mint mone=one;
		for(int j=1;j<N;++j,mone/=2){
			probs[i][j]=probs[i][j-1]+choose(i+j-2,i-1)*mone;
		}
	}
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	mint res=0;
	for(int i=0;i<n;++i)res+=solve(i);
	cout<<res/n<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}