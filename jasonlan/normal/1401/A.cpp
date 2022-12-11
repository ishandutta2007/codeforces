#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<bitset>
using namespace std;
const int maxn=101000;
int T,k,a;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	T=read();
	while(T--){
		a=read();k=read();
		if(a<k)
			printf("%d\n",k-a);
		else
			printf("%d\n",(k^a)&1);
	}
	return 0;
}