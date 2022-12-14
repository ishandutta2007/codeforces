#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
long long n,a[200006],s,t;
int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read(),s+=a[i];
	for(int i=1; i<=n; ++i){
		t+=a[i];///>>1 -9 -7 //9 7  u ui i  //ll L
		if(t>=(s+1)/2){
		    cout<<i;
		    return 0;
		}
	}
}