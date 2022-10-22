#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair

const int N=2002,mod=1e9+7;

ll dp1[N][N],dp2[N][N],ans[N],n,k,anss;
string s;

ll up(char s){
	return 'z'-s;
}
ll down(char s){
	return s-'a';

}
int main(){
	cin>>n>>k;
	cin>>s;
	s=' '+s;
	n++,k++;
	dp1[0][0]=1;
	ans[0]=1;
	f(i,1,n){
		anss=ans[k-1];
		f(j,0,k)
			dp2[i][j]=(down(s[i])*ans[j])%mod,ans[j]=(ans[j]+dp2[i][j])%mod;
		f_(j,i-1,max(1ll*0,i-1-(k/(n-i))-1))
			f(l,(n-i)*(i-j),k){
				ans[l]=(ans[l]+((dp1[j][l-(n-i)*(i-j)]+dp2[j][l-(n-i)*(i-j)])%mod*up(s[i]))%mod)%mod;
				dp1[i][l]=(dp1[i][l]+((dp1[j][l-(n-i)*(i-j)]+dp2[j][l-(n-i)*(i-j)])%mod*up(s[i]))%mod)%mod;
			}
	}
	cout<<(dp1[n-1][k-1]+dp2[n-1][k-1]+anss)%mod;
}