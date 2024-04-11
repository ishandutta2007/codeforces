#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,m=3,S=5,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int n,q,L,R,C,a[N][S],A[N][S],B[N][S],vis[N][S],ps[N],fenwik[2][N];

void add(int x, int val,int s){ for(x++;x<N;x+=x&-x) fenwik[s][x]+=val; }
int get(int x,int s) { int res=0; for (x++;x>0;x-=x&-x) res+=fenwik[s][x]; return res; }

void dfs(int x,int y){
	vis[x][y]=C;
	minm(L,x);
	maxm(R,x);
	f(i,0,4){
		int u=x+dx[i],v=y+dy[i];
		if(vis[u][v] || a[u][v]==0) continue ;
		dfs(u,v);
	}
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(j,1,m+1){
		f(i,1,n+1){
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	f(i,1,n+1) ps[i]=ps[i-1]+a[i][2];
	f(i,1,n+1){
		f(j,1,m+1){
			if(a[i][j]==0) continue ;
			A[i][j]=i;
			if(a[i-1][j]==1) A[i][j]=A[i-1][j];
		}
	}
	f_(i,n,1){
		f(j,1,m+1){
			if(a[i][j]==0) continue ;
			B[i][j]=i;
			if(a[i+1][j]==1) B[i][j]=B[i+1][j];
		}
	}
	f(i,1,n+1){
		f(j,1,m+1){
			if(a[i][j]==1 && vis[i][j]==0){
				C++;
				L=n,R=1;
				dfs(i,j);
				add(L,1,0);
				add(R,1,1);
			}
		}
	}
	cin>>q;
	while(q--){
		int l,r,ans;
		cin>>l>>r;
		ans=get(r,0)-get(l-1,1);
		if(a[r][1] && a[r][3] && A[r][1]<=l && A[r][3]<=l && ps[r]==ps[l-1]){
			cout<<2<<endl;
			continue ;
		}
		if(a[l][1] && a[l][3] && vis[l][1]==vis[l][3]){
			int x=min(B[l][1],B[l][3]);
			minm(x,r);
			if(ps[x]==ps[l-1]) ans++;
		}
		if(a[r][1] && a[r][3] && vis[r][1]==vis[r][3]){
			int x=max(A[r][1],A[r][3]);
			maxm(x,l);
			if(ps[r]==ps[x-1]) ans++;
		}
		cout<<ans<<endl;
	}
}
/*
7
1110111
1000001
1110111
12
100101011101
110110010110
010001011101
9 9
*/