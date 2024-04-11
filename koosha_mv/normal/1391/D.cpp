#include <bits/stdc++.h>
#include <iostream>
using namespace std;
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

const int N=1e6+9;

int n,m,t,ans,dp[2][8],up[8];
string ma[N],s[N];
vector<int> v[8];

bool check(int mask1,int mask2){
	int sum=0;
	f(i,0,2)
		sum+=is_bit(mask1,i)+is_bit(mask2,i);
	if(sum%2==0) return 0;
	sum=0;
	f(i,1,3)
		sum+=is_bit(mask1,i)+is_bit(mask2,i);
	if(sum%2==0) return 0;
	return 1;
}
void make_v(){
	f(i,0,8)
		f(j,0,8)	
			if(check(i,j))
				v[i].pb(j);
}
void do_it(){
	if(n<=m){
		f(i,0,n)
			s[i]=ma[i];
		return ;
	}
	swap(n,m);
	f(i,0,n)
		f(j,0,m)
			s[i]+=ma[j][i];
}
int calc(int x,int mask){
	int res=0;
	f(i,0,n)
		res+=((s[i][x]-'0')!=is_bit(mask,i));
	return res;
}
void solve(){
	if(n==1){ cout<<0; return ;}
	if(n==2){
		int res=0;
		f(i,0,m){
			ans+=(i%2==0 && s[0][i]==s[1][i]);
			ans+=(i%2==1 && s[0][i]!=s[1][i]);
			//cout<<i%2<<" "<<(s[0][i]==s[1][i])<<endl;
		}
		f(i,0,m){
			res+=(i%2==1 && s[0][i]==s[1][i]);
			res+=(i%2==0 && s[0][i]!=s[1][i]);
		}
		cout<<min(ans,res);
		return ;
	}
	f(i,0,8) dp[0][i]=calc(0,i);
	f(i,1,m){
		int s=i%2;
		f(mask,0,8){
			dp[s][mask]=N;
			int mv=calc(i,mask);
			f(j,0,v[mask].size())
				minm(dp[s][mask],dp[1-s][v[mask][j]]);	
			dp[s][mask]+=mv;
		}
	}
	ans=N;
	f(i,0,8)
		minm(ans,dp[(m-1)%2][i]);
	cout<<ans;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	make_v();
	cin>>n>>m;
	f(i,0,n)
		cin>>ma[i];
	do_it();
	if(n>3) return cout<<-1,0;
	solve();
}