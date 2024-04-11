#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+9,H=1,mod[H]={998244353},base=39;

int n,res,ans[N],Pow[H][N],hsh[H][N];
vector<pair<int,int> > v[H][N];
map<int,bool> mark[H][N];
string s;

bool check(int l,int r){
	f(i,0,H){
	   //cout<<1;
		int hs=(hsh[i][r]-1ll*hsh[i][l]*Pow[i][r-l]%mod[i]+mod[i])%mod[i];
		//cout<<"HS : "<<hs<<endl;
		if(!mark[i][r-l][hs]) return 0;
	}
	return 1;
}
void add(int l,int r){
   f(i,0,H){
		int hs=(hsh[i][r]-1ll*hsh[i][l]*Pow[i][r-l]%mod[i]+mod[i])%mod[i];
		v[i][r].pb(mp(hs,r-l));
	}
}
int main(){
   cin>>n>>s;
   reverse(s.begin(),s.end());
   s=' '+s;
   f(h,0,H){
      mark[h][0][0]=1;
		f(i,0,n+1){
			if(i==0) Pow[h][i]=1;
			else{
				Pow[h][i]=1ll*Pow[h][i-1]*base%mod[h];
				hsh[h][i]=(1ll*hsh[h][i-1]*base%mod[h]+s[i]-'a')%mod[h];
			}
		}
	}
	ans[0]=1;
   f(i,1,n+1){
   	int l=i-1,r=i+1000;
   	while(l+1<r){
   	   int mid=(l+r)/2;
   	   if(check(i-1,mid)) l=mid;
   	   else r=mid;
   	}
   	ans[i]=r;
   	while(ans[i]<=n && (check(i-1,ans[i]-1) || check(i,ans[i]))){
   	   add(i-1,ans[i]);
   		ans[i]++;
   	}
   	//cout<<i<<" "<<ans[i]<<endl;
   	maxm(res,ans[i]-i);
   	f(h,0,H){
   		f(j,0,v[h][i].size()){
				mark[h][v[h][i][j].S][v[h][i][j].F]=1;
			}
		}
	}
	cout<<res;
}