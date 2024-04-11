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

const int N=1e6+99,S=18,mod=998244353;

int n,q,Cnt,a[N],Pow[S][N],dp[S][(1<<S)];
string s;

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,1,S){
		Pow[i][0]=1;
		f(j,1,N) Pow[i][j]=1ll*Pow[i][j-1]*i%mod;
	}
	cin>>n>>s>>q;
	f(i,0,s.size()) if(s[i]=='?') Cnt++;
	s=' '+s;
	f(i,1,n){
		int cnt=Cnt,mask=0;
		for(int j=1;j<=min(i,n-i) && (s[i+1-j]=='?' || s[i+j]=='?' || s[i+1-j]==s[i+j]);j++){
			if(s[i+1-j]=='?' && s[i+j]=='?') cnt--;
			if(s[i+1-j]=='?' && s[i+j]!='?') mask|=(1<<(s[i+j]-'a')),cnt--;
			if(s[i+1-j]!='?' && s[i+j]=='?') mask|=(1<<(s[i+1-j]-'a')),cnt--;
			f(k,1,S) Add(dp[k][mask],Pow[k][cnt]);
		}
	}
	f(i,1,n+1){
		//if(i==3 || i==4) continue ;
		int cnt=Cnt,mask=0;
		for(int j=1;j<=i && j<=n-i+1 && (s[i+1-j]=='?' || s[i+j-1]=='?' || s[i+1-j]==s[i+j-1]);j++){
			//cout<<i<<" -- "<<j<<endl;
			if(s[i+1-j]=='?' && s[i+j-1]=='?' && j!=1) cnt--;
			if(s[i+1-j]=='?' && s[i+j-1]!='?') mask|=(1<<(s[i+j-1]-'a')),cnt--;
			if(s[i+1-j]!='?' && s[i+j-1]=='?') mask|=(1<<(s[i+1-j]-'a')),cnt--;
			//cout<<i<<" - "<<j<<" "<<Pow[2][cnt]<<endl;
			f(k,1,S) Add(dp[k][mask],Pow[k][cnt]);
		}
	}
	//cout<<dp[2][0]+dp[2][1]+dp[2][2]+dp[2][3]<<endl;
	//return 0;
	f(i,1,S){
		f(j,0,S){
			f(mask,0,(1<<S)){
				if(bit(mask,j)==0){
					Add(dp[i][mask^(1<<j)],dp[i][mask]);
				}
			}
		}
	}
	while(q--){
		string t;
		int mask=0;
		cin>>t;
		f(i,0,t.size()) mask|=(1<<(t[i]-'a'));
		cout<<dp[nb(mask)][mask]<<'\n';
	}
}
/*
7
ab??aba
1
ab
*/