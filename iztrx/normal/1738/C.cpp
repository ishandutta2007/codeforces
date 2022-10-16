#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define N 1000004
#define ll long long
#define mid (l+r>>1)
#define ls k<<1
#define rs k<<1|1
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);

int T,n,i,x,j,k,s[N],y,a[N],t1,t2,b[N],c[N],d[N],f[104][105][2];
int main(){
	IOS;
	cin>>T;
	for(i=0;i<=100;++i){
		for(j=0;j<=100;++j){
			if(i==0||j==0){
				f[i][j][(j+1>>1)&1]=1;
			}
			else{
				f[i][j][0]=(f[i-1][j-1][1]&(j<=1||f[i][j-2][1]));
				f[i][j][0]|=(f[i-1][j-1][0]&(i<=1||f[i-2][j][0]));
				f[i][j][1]=(f[i-1][j-1][0]&(j<=1||f[i][j-2][0]));
				f[i][j][1]|=(f[i-1][j-1][1]&(i<=1||f[i-2][j][1]));
			}
		}
	}
	while(T--){
		cin>>n;int f1=0,f2=0;
		for(i=1;i<=n;++i)cin>>a[i],a[i]+=1000000000,a[i]&=1;
		for(i=1;i<=n;++i)if(a[i]==0)f1++;else f2++;
		if(f[f1][f2][0])cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}