#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005,P=998244353;
int pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=(LL)a*a%P) if(b&1)r=(LL)r*a%P;
	return r;
}
int n,fac[N],fin[N];
char s[N];
int C(int a,int b){
	return(LL)fac[a]*fin[b]%P*fin[a-b]%P;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=N-1;i++)fac[i]=(LL)fac[i-1]*i%P;
	fin[N-1]=pow(fac[N-1],P-2);
	for(int i=N-1;i;i--)fin[i-1]=(LL)fin[i]*i%P;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		int a=0,b=0,c=0;
		for(int i=1;i<=n+1;i++){
			if(s[i]=='0'||i>n){
				a+=c/2+(i<=n);
				b+=c/2;
				c=0;
			}
			else c++;
		}
		printf("%d\n",C(a,b));
	}
}