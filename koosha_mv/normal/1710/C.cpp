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
#define int ll

const int N=2e5+99,mod=998244353;

int n,m,a[N],dp[N][8][8];
string s;
vector<int> vec;

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>s; n=s.size();
	dp[0][7][7]=1;
	f(i,0,n){
		f(mask,0,8){
			f(task,0,8){
				f(now,0,8){
					int nmask=mask,ntask=0,b=0; 
					f(j,0,3){
						if(bit(mask,j)==1 && bit(now,j)==1 && s[i]=='0')		b=1;
						if(bit(mask,j)==1 && bit(now,j)==0 && s[i]=='1') nmask^=(1<<j);
						if(bit(now,j)!=bit(now,(j+1)%3)){
							ntask^=(1<<j);
						}
					}
					if(b==1) continue ;
					if(ntask==0) ntask=7;
					Add(dp[i+1][nmask][task&ntask],dp[i][mask][task]);
				}
			}
		}
	}
	int ans=0;
	f(i,0,8) Add(ans,dp[n][i][0]);
	cout<<ans;
}