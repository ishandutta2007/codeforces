#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
const int MOD=1e9+7;
char tmp[N];
string s,t[N];char d[N];
int a[N][10],b[N][10];
int main(){
	scanf("%s",tmp);s=tmp;
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",tmp);t[i]=tmp;
		d[i]=tmp[0];t[i]=t[i].substr(3);
	}
	for(int i=0;i<10;++i)a[n][i]=10,b[n][i]=i;
	for(int i=n-1;~i;--i){
		int p=1,q=0;
		for(int j=0;j<t[i].size();++j){
			int p2=1LL*p*a[i+1][t[i][j]-48]%MOD;
			int q2=(1LL*q*a[i+1][t[i][j]-48]%MOD+b[i+1][t[i][j]-48])%MOD;
			p=p2,q=q2;
		}
		for(int j=0;j<10;++j)a[i][j]=a[i+1][j],b[i][j]=b[i+1][j];
		a[i][d[i]-48]=p,b[i][d[i]-48]=q;
	}
	int p=1,q=0;
	for(int i=0;i<s.size();++i){
		int p2=1LL*p*a[0][s[i]-48]%MOD;
		int q2=(1LL*q*a[0][s[i]-48]%MOD+b[0][s[i]-48])%MOD;
		p=p2,q=q2;
	}
	printf("%d\n",q);
	return 0;
}