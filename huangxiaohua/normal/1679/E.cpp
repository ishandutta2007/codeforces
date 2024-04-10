#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,m,n,t,num;
ll f[20][300500],pw[20][300500];
char s[10050];

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

void chk(int l,int r,int t){
	int msk=0,t1=num;
	ll sb=1;
	while(l>=1&&r<=n){
		if(s[l]=='?'&&s[r]=='?')sb=sb*t%M,t1-=1+(l!=r);
		if(s[l]=='?'&&s[r]!='?')msk|=b(s[r]-'a'+1),t1-=1;
		if(s[l]!='?'&&s[r]=='?')msk|=b(s[l]-'a'+1),t1-=1;
		if(s[l]!='?'&&s[r]!='?'&&s[l]!=s[r])break;
		f[t][msk]=su(f[t][msk],sb*pw[t][t1]%M);
		l--;r++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>s+1;
	for(i=1;i<=17;i++){
		pw[i][0]=1;
		for(j=1;j<=300000;j++)pw[i][j]=pw[i][j-1]*i%M;
	}
	for(i=1;i<=n;i++)num+=(s[i]=='?');
	for(i=1;i<=n;i++)for(j=1;j<=17;j++){
		chk(i,i,j);
		if(i<n)chk(i,i+1,j);
	}
	for(t=1;t<=17;t++)for(i=1;i<=17;i++)for(j=1;j<b(18);j++)if(j&b(i))f[t][j]=su(f[t][j],f[t][j^b(i)]);
	cin>>t;
	while(t--){
		int msk=0;string s;
		cin>>s;
		for(auto i:s)msk|=b(i-'a'+1);
		cout<<f[s.size()][msk]<<'\n';
	}
}