#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,s[100500],m,m1,l,r;
ll f[2050][2050],res;
char sb;

int main(){
	f[0][0]=1;
	for(i=1;i<=2005;i++){
		f[i][0]=f[i-1][1];
		for(j=1;j<=i;j++){
			f[i][j]=(f[i-1][j-1]+f[i-1][j+1])%M;
		}
	}
	scanf("%d%d",&n,&m);
	n-=m;
	for(i=1;i<=m;i++){
		sb=getchar();
		while(sb!='('&&sb!=')'){sb=getchar();}
		if(sb=='('){s[++m1]=1;}
		else{
			if(m1&&s[m1]==1){m1--;}
			else{s[++m1]=2;}
		}
	}
	for(i=1;i<=m1;i++){
		if(s[i]==2){l++;}
		else{r++;}
	}
	for(i=0;i<=n;i++){
		for(j=l;j<=n;j++){
			if(j>i||(j-l+r)>(n-i)){continue;}
			res+=f[i][j]*f[n-i][j-l+r];res%=M;
		}
	}
	printf("%lld",res);
}