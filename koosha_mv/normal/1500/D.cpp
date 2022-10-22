#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1531,K=11,mx=2e8;

int n,m,cnt,o,ans[N],mark[N*N],a[N][N];
vector<int> vec[N],d[N][N],r[N][N];

void read(){
	cin>>n>>m;
	f(i,1,n+1){
		f(j,1,n+1){
			cin>>a[i][j];
		}
	}	
}
void make(){
	f_(i,n,1){
		f_(j,n,1){
			d[i][j]=d[i+1][j];
			r[i][j]=r[i][j+1];
			f(k,0,d[i][j].size()){
				if(a[d[i][j][k]][j]==a[i][j]){
					d[i][j].erase(d[i][j].begin()+k);
					break;
				}
			}
			f(k,0,r[i][j].size()){
				if(a[i][r[i][j][k]]==a[i][j]){
					r[i][j].erase(r[i][j].begin()+k);
					break;
				}
			}
			int e1=-1,e2=-1;
			if(d[i][j].size()>m) e1=d[i][j].back();
			if(r[i][j].size()>m) e2=r[i][j].back();
			vector<int> D=d[i][j],R=r[i][j];
			d[i][j].clear();
			r[i][j].clear();
			d[i][j].pb(i);
			r[i][j].pb(j);
			f(k,0,D.size()) if(D[k]!=e1) d[i][j].pb(D[k]);
			f(k,0,R.size()) if(R[k]!=e2) r[i][j].pb(R[k]);
		}
	}
}
void solve(int u,int v){
	int x=u,y=v;
	cnt=0;
	while(u && v){
		f(k,0,d[u][v].size()){
			o++;
			if(d[u][v][k]<=x){
				int col=a[d[u][v][k]][v];
				vec[d[u][v][k]].pb(col);
				if(++mark[col]==1) cnt++;
			}
		}
		f(k,0,r[u][v].size()){
			o++;
			if(r[u][v][k]<=y){
				int col=a[u][r[u][v][k]];
				vec[u+r[u][v][k]-v].pb(col);
				if(++mark[col]==1) cnt++;
			}
		}
		while(cnt>m){
			o++;
			f(i,0,vec[x].size()){
				mark[vec[x][i]]--;
				if(mark[vec[x][i]]==0){
					cnt--;
				}
			}
			x--,y--;
		}
		ans[x-u+1]++;
		u--,v--;
	}
	while(x){
		o++;
		f(i,0,vec[x].size()){
			o++;
			mark[vec[x][i]]--;
			if(mark[vec[x][i]]==0){
				cnt--;
			}
		}
		x--;
	}
	f(i,1,n+1) vec[i].clear();
}
void Main(){
	f(i,1,2*n){
		solve(n-max(0,i-n),min(n,i));
	}
	f_(i,n,1)
		ans[i]+=ans[i+1];
	f(i,1,n+1)	
		cout<<ans[i]<<" ";
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	read();
	make();
	Main();
}