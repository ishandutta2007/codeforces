#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define IOS ios::sync_with_stdio(0)
#define N 1000005
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
void py(){cout<<"Yes\n";}
void pn(){cout<<"No\n";}
int n,T,c1,c2,i,zz,fl,len,j,las,c[N],sg[N];
string s;
int main(){
	IOS;
	sg[2]=1;
	for(i=3;i<=100;++i){
			memset(c,0,sizeof(c));
			for(j=1;j<i;++j){
				c[sg[j-1]^sg[i-j-1]]=1;
			}
			for(j=0;c[j];++j);
			sg[i]=j;
		}
		for(i=101;i<=500000;++i)sg[i]=sg[i-34]; 
	cin>>T;
	while(T--){
		cin>>n>>s;c1=c2=0;
		for(i=0;i<n;++i){
			if(s[i]=='R')++c1;
			else ++c2;
		}
		if(c1>c2)cout<<"Alice\n";
		else if(c1<c2)cout<<"Bob\n";
		else{
		zz=0;
		s+='?';
		for(las=i=0;i<n;++i){
			if(i==n-1||s[i]==s[i+1]){
				len=i-las+1;
				las=i+1;
				zz^=sg[len];
			}
		}
		if(zz)cout<<"Alice\n";
		else cout<<"Bob\n";
		}
	}
}