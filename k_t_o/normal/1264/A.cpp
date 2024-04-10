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
#define N 500005
int T,n,p[N],g,s,b,_g,_s,_b,ma;
set<int>S;

int main()
{
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)p[i]=read();
		S.clear(); _g=_s=_b=ma=0;
		for(int i=1;i<n;++i)if(p[i]!=p[i+1])S.insert(i);
		for(int i=1;i<n;++i)if(p[i]!=p[i+1]){
			g=i;
			auto it=S.lower_bound(i+i+1);  //sli  jieshu
			
			
			
			if(it==S.end())break;
			auto it2=S.upper_bound(n/2);
			
			//if(it2==S.end())break;
			if(it2==S.begin())break;
			--it2; // b jieshu
			if(*it==*it2)break;
			s=*it-i;
			b=*it2-*it;
			
			if(g>=b)continue;
			if(g+s+b>ma){
				ma=g+s+b;
				_g=g; _s=s; _b=b;
			}
		}
		printf("%d %d %d\n",_g,_s,_b);
	} 
}
/*
1
12
5 4 4 3 2 2 1 1 1 1 1 1
*/