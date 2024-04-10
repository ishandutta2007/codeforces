#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n;
int a=0,b=0,c=0,num=1;
int f[M];
char s[M];
void add(int &x,int y){x=(x+y)%mod;x=(x+mod)%mod;}
void mul(int &x,int y){x=1ll*x*y%mod;}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='a')add(a,num);
		if(s[i]=='b')add(b,a);
		if(s[i]=='c')add(c,b);
		if(s[i]=='?'){
			mul(c,3);
			add(c,b);
			mul(b,3);
			add(b,a);
			mul(a,3);
			add(a,num);
			num=3ll*num%mod;
		}
	}
	printf("%d\n",c);
	return 0; 
}
/*
4
????
*/