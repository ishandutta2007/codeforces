#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005;
pair<int,int> adj[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n,m,p,s[20],cn[20];;
vector<pair<int,int> > C[12],mv;
char t[N][N];
 
void move(int pl){
	int nx, ny;
	for(int i = 0; i < s[pl]; i++){
		if(C[pl].size() == 0) return ;
		mv.clear();
		for(auto cell : C[pl]){
			for(auto del:adj){
				nx=cell.F + del.F;
				ny=cell.S + del.S;
				if(t[nx][ny] == '.'){
					t[nx][ny]=((char)(pl + '1'));
					mv.pb({nx, ny});
				}
			}
		}
		C[pl].clear();
		for(auto x:mv) C[pl].pb(x);
	}
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>p;
	f(i,0,p) cin >> s[i];
	string st;
	f(i,1,n+1){
		cin >> st;
		f(j,1,m+1){
			t[i][j] = st[j - 1];
			if( '0'<=t[i][j] && t[i][j]<='9'){
				C[t[i][j]-'1'].pb({i, j});
			}
		}
	}
	f(i,0,p*n*m)
		move(i % p);
	f(i,1,n+1)
		f(j,1,m+1)
			if( '1' <= t[i][j] and t[i][j] <= '9') cn[t[i][j] - '1'] ++;
	f(i,0,p) cout<<cn[i]<<" ";
}