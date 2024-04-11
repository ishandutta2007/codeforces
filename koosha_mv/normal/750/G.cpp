#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcountll(x)
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

const int N=1e6+99,lg=55;

int n,s,ans,a[N],dp[lg][lg<<1][2];

int calc(int x,int p){
	if(p==0) return 1;
	int res=0;
	f(i,1,x+1){
		int s=p+i;
		if(nb(p+i)==i && p+i<=(1ll<<(x+1))-2 && (p&1)==(i&1)){
			res++;
		}
	}
	return res;
}
int calc2(int x,int y,int p){
	if(p==0) return 1;
	int res=0;
	f(i,1,x+y+1){
		int s=p+i;
		if(s&1) continue ;
		s/=2;
		memset(dp,0,sizeof dp);
		f(k1,0,lg) f(k2,0,lg) f(k3,0,2) dp[k1][k2][k3]=0;
		dp[0][0][0]=1;
		f(id,0,lg-1){
			f(cnt,0,i+1){
				f(b,0,2){
					f(bx,0,2){
						f(by,0,2){
							if((id>=x && bx==1) || (id>=y && by==1) || bit(s,id)!=((b+bx+by)&1)) continue ;
							dp[id+1][cnt+bx+by][(b+bx+by)/2]+=dp[id][cnt][b];
						}
					}
				}
			}
		}
		res+=dp[lg-1][i][0];
	}
	return res;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>s;
	f(i,0,lg){
		if(s<(1ll<<(i+1))-1) break;
		ans+=calc(i,s%((1ll<<(i+1))-1));
	}
	f(i,1,lg){
		f(j,1,lg){
			int zarib=(1ll<<(i+1))+(1ll<<(j+1))-3;
			if(s<zarib) continue ;
			int rem=s%zarib;
			rem-=(1ll<<i)-1;
			if(rem<0) continue ;
			ans+=calc2(i-1,j-1,rem);
			
			//cout<<i-1<<" "<<j-1<<" "<<rem<<" -> "<<calc2(i-1,j-1,rem)<<" "<<calc2(i-1,j-1,rem)<<endl;
		}
	}
	cout<<ans;
}
/*
123
16
*/