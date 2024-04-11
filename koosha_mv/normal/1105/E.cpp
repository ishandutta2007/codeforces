#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e5+9,M=41;

int n,m,x,matris[M][M],cnt=1,a[N],m1,m2,dp[(1<<20)],e[(1<<20)][20],ans,b[M],check[(1<<20)],mj[22][(1<<20)];
map<string,int> name;
vector<int> g[M];
string s;

void solve(int x){
	int cx=x,k=1,c=0,mn=50;
	dp[x]=0;
	f(i,0,m1){
		if(x%2){
			b[c]=i+1;
			maxm(dp[cx],dp[cx-(1<<i)]);
			c++;
			minm(mn,dp[cx-(1<<i)]);
		}
		x/=2;
	}
	if(mn==c-1 && c!=2) dp[cx]=c;
	if(c==2 && matris[b[0]][b[1]]==0) dp[cx]=2;
}
bool mojaver(int x,int y){
	if(mj[x][y]>=0) return mj[x][y];
	int cy=y;
	if(y==0){mj[x][y]=1;return 1;}
	f(i,0,m-m1){
		if(cy%2){
			if(mojaver(x,y-(1<<i))==0){mj[x][y]=0;  return 0;}
			if(matris[x][i+1+m1]==1){ mj[x][y]=0; return 0;}
			mj[x][y]=1;
			return 1;
		}
		cy/=2;
	}
}
void chk(int x){
	int cx=x,c=0,k=1;
	f(i,0,m-m1){
		if(cx%2){
			b[c]=i+1;
			k=(check[x-(1<<i)] && k),c++;
		}
		cx/=2;
	}
	check[x]=0;
	if(k && c!=2) check[x]=1;
	if(c==2 && matris[b[0]+m1][b[1]+m1]==0) check[x]=1;
	if(check[x]==0) return ;
	int p=0;
	f(i,0,m1){
		if(mojaver(i+1,x)) p+=(1<<i);
	}
	maxm(ans,dp[p]+c);
}

int main(){
	cin>>n>>m;
	if(m==1) return cout<<1,0;
	f(i,0,n){
		cin>>x;
		if(x-1){
			cin>>s;
			if(!name[s]) name[s]=cnt++;
			a[i]=name[s];
			f_(j,i-1,0){
				if(a[j]==0) break;
				if(matris[a[i]][a[j]]==0 && a[i]!=a[j]){
					matris[a[i]][a[j]]=matris[a[j]][a[i]]=1;
					g[a[i]].pb(a[j]);
					g[a[j]].pb(a[i]);
				}		
			}
		}
	}
	m1=m/2;
	f(i,0,21) f(j,0,(1<<20)) mj[i][j]=-1;
	f(i,0,(1<<m1)){solve(i);}
	f(i,0,(1<<(m-m1))) chk(i);
	cout<<ans<<endl;
	
}