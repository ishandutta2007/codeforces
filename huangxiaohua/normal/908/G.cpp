#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int i,j,k,t,n,m,a[66];
ll res,c[707][707],p[11][2000];
string s;

void get(int n){
	int i,j,k=0;
	for(i=9;i>=1;i--){k+=a[i];
		for(j=0;j<=n;j++){
			res=su(res,c[n][j]*p[10-i][j]%M*p[i][n-j]%M*p[10][k+j-1]%M);
		}
	}
}

void dp(int x){
	if(!x){get(0);return;}
	for(int i=0;i<s[x];i++){a[i]++;get(x-1);a[i]--;}
	a[s[x]]++;dp(x-1);
}

int main(){
	c[0][0]=1;
	for(j=0;j<=10;j++)p[j][0]=1;
	for(i=1;i<=701;i++){
		for(c[i][0]=j=1;j<=i;j++)c[i][j]=su(c[i-1][j-1],c[i-1][j]);
		for(j=1;j<=9;j++)p[j][i]=p[j][i-1]*j%M;
		p[10][i]=su(p[10][i-1]*10%M,1);
	}
	cin>>s;n=s.size();
	reverse(s.begin(),s.end());s="X"+s;
	for(auto &i:s)i-='0';
	dp(n);cout<<res;
}