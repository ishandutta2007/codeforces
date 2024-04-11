#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
ll n,dp[N][129],e=1e9,g[N][9],p,k,tvn[9],ct,ans;
vector<int> t[9];
pair<int,int> a[N];
int main(){
	tvn[0]=1;
	f(i,1,8) tvn[i]=tvn[i-1]*2;
	f(i1,0,2){
	f(i2,0,2){
	f(i3,0,2){
	f(i4,0,2){
	f(i5,0,2){
	f(i6,0,2){
	f(i7,0,2){
		t[i1+i2+i3+i4+i5+i6+i7].pb(i1+i2*2+i3*4+i4*8+i5*16+i6*32+i7*64);
	}
	}
	}
	}
	}
	}
	}
	cin>>n>>p>>k;
	f(i,1,n+1){
		gett(a[i].F);
		a[i].F=e-a[i].F;
		a[i].S=i;
	}
	sort(a+1,a+n+1);
	f(i,1,n+1){
		f(j,0,p)
			gett(g[i][j]);
	}
	f(i,1,129) dp[0][i]=-1e18;
	f(i,1,n+1){
		a[i].F=e-a[i].F;
		f(j,0,p+1){
		f(l,0,t[j].size()){
			dp[i][t[j][l]]=dp[i-1][t[j][l]]+(a[i].F*(i<=k+j));		
			ct=t[j][l];
			f_(j2,6,0){
				if(ct>=tvn[j2]){
					ct-=tvn[j2];
					maxm(dp[i][t[j][l]],dp[i-1][t[j][l]-tvn[j2]]+g[a[i].S][j2]);
				}
			}
			maxm(ans,dp[i][t[j][l]]);
		}
		}
	}
	cout<<ans<<endl;
}