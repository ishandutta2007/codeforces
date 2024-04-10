#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m;
char s1[3050],s2[3050];
ll f[3050][3050],res;

int main(){
	gets(s1+1);
	gets(s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	
	for(i=1;i<=m;i++){
		if(s1[1]==s2[i]){f[i][i]=2;}
	}
	for(i=m+1;i<=n;i++){
		f[i][i]=2;
	}
	
	for(i=2;i<=n;i++){
		for(j=1;j+i-1<=n;j++){
			int l=j,r=j+i-1;
			if(l>m||s2[l]==s1[i]){f[l][r]+=f[l+1][r];}
			if(r>m||s2[r]==s1[i]){f[l][r]+=f[l][r-1];}
			f[l][r]%=M;
			if(l==1&&r>=m){res+=f[l][r];
			}
		}
	}
	if(m==1){res+=f[1][1];}
	printf("%lld",res%M);
}