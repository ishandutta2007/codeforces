#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=505,S=4,dx[S]={1,-1,0,0},dy[S]={0,0,1,-1};

int n,k,t,a[S],dist[N][N];
int g[N][N][S];

void dijikastra(){
	set<pair<int,pair<int,int> > > s;
	f(i,0,n+1) f(j,0,n+1) dist[i][j]=(i==0 || j==0 || i==n || j==n ? 0 : N*N),s.insert({dist[i][j],{i,j}});
	while(s.size()){
		int x=(*s.begin()).S.F,y=(*s.begin()).S.S,d=(*s.begin()).F;
		//cout<<x<<" "<<y<<" : "<<dist[x][y]<<endl;
		s.erase(*s.begin());
		f(i,0,4){
			int u=x+dx[i],v=y+dy[i];
			if(dist[x][y]+g[x][y][i]<dist[u][v]){
				//cout<<x<<" "<<y<<" "<<i<<" : "<<g[x][y][i]<<endl;
				s.erase({dist[u][v],{u,v}});
				dist[u][v]=dist[x][y]+g[x][y][i];
				s.insert({dist[u][v],{u,v}});
			}
		}
	}
	cout<<k-dist[n/2][n/2]<<'\n';
}
void Main(){
	cin>>k>>n;
	
	f(i,0,k){
		f(j,0,S){
			cin>>a[j];
		}
		if(a[0]>a[2] || a[1]>a[3]){
			swap(a[0],a[2]);
			swap(a[1],a[3]);
		}
		if(a[0]<a[2]){
			int r1=a[0],c1=a[1]-1,r2=a[0],c2=a[1],d=2;
			g[r1][c1][d]++;
			g[r2][c2][d^1]++;
			//cout<<r1<<" "<<c1<<" "<<d<<endl;
			//cout<<r2<<" "<<c2<<" "<<(d^1)<<endl;
			d^=1;
			r1=n-r1;
			c1=n-c1;
			r2=n-r2;
			c2=n-c2;
			//cout<<r1<<" "<<c1<<" "<<d<<endl;
			//cout<<r2<<" "<<c2<<" "<<(d^1)<<endl;
			g[r1][c1][d]++;
			g[r2][c2][d^1]++;
		}
		else{
			int r1=a[0]-1,c1=a[1],r2=a[0],c2=a[1],d=0;
			g[r1][c1][d]++;
			g[r2][c2][d^1]++;
			//cout<<r1<<" "<<c1<<" "<<d<<endl;
			//cout<<r2<<" "<<c2<<" "<<(d^1)<<endl;
			d^=1;
			r1=n-r1;
			c1=n-c1;
			r2=n-r2;
			c2=n-c2;
			//cout<<r1<<" "<<c1<<" "<<d<<endl;
			//cout<<r2<<" "<<c2<<" "<<(d^1)<<endl;
			g[r1][c1][d]++;
			g[r2][c2][d^1]++;
		}
	}
	dijikastra();
	f(i,0,n+1) f(j,0,n+1) f(s,0,S) g[i][j][s]=0;
}
int main(){
	cin>>t;
	while(t--){
		Main();
	}	
}
/*
1
7 2
1 1 1 2
2 1 2 2
1 1 1 2
1 1 2 1
1 2 2 2
1 1 2 1
1 2 2 2
*/