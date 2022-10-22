#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=209;
int t,n,x,p,an,sz[N],a[N],mark[N],mat[N][N],mk[N];
vector<int> g[N];
/*1
6
3 2 5 6
2 4 6
3 1 3 4
2 1 3
4 1 2 4 6
*/

int satis(int x,int y){
	f(i,x-g[y].size()+1,x){
		if(mat[y][a[i]]==0){
			return 0;
		}
	}
	f(i,0,g[y].size())
		if(mk[g[y][i]]==0)
			return g[y][i];
	return 0;
}
bool solve(int x){
	a[0]=x;
	fill(mk,mk+n+2,0);
	fill(mark,mark+n+2,0);
	mk[x]=1;
	f(i,1,n){
		p=0;
		f(j,1,n){
			if(mark[j]==0 && g[j].size()<=i+1){
				int m=satis(i,j);
				if(m>0){
					an=m,p++;
					mark[j]=1;
				}
			}
		}
		if(p!=1) return 0;
		mk[an]=1;
		a[i]=an;
	}
	return 1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,0,n+1) f(j,0,n+1) mat[i][j]=0;
		f(i,1,n){
			g[i].clear();
			cin>>sz[i];
			f(j,0,sz[i]){
				cin>>x;
				g[i].pb(x);
				mat[i][x]=1;
			}
		}
		f(i,1,n+1){
			fill(mark,mark+n+2,0);
			if(solve(i)){
				print(a,n);
				break;
			}
		}
	}
}