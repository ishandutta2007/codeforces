#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=3e5+99;

int n,t,cnt[2],mv[2][2],a[30][N];

void Main(){
	int ans=N;
	string s,t;
	cnt[0]=cnt[1]=0;
	f(i,0,2) f(j,0,2) mv[i][j]=0;
	cin>>n>>s>>t;
	f(i,0,n){
		if(s[i])
		cnt[s[i]!=t[i]]++;
		mv[s[i]-'0'][t[i]-'0']++;
	}
	if(cnt[1]%2==0 && mv[0][1]==mv[1][0]) ans=cnt[1];
	if(cnt[0]%2==1 && mv[1][1]==mv[0][0]+1) minm(ans,cnt[0]);
	//cout<<cnt[0]<<" "<<cnt[1]<<endl;
	cout<<(ans==N ? -1 : ans)<<endl;
}

main(){
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}