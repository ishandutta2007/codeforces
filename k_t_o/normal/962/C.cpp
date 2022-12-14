#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int op[15],k,fl,n,s,I,ans;

void dfs(int p, int d, int pr)  
{
	if(!p)return;
	if(d>I)return;
	if(fl)return;
	if((int)((int)sqrt(p+0.1)*(int)sqrt(p+0.1))==p){
		fl=1;
		return;
	}

	for(int i=pr+1; i<=10; ++i){
		if(p>=op[i]){
			int s=p/op[i]/10; 
			int o=0;
			if(!s){
				int g=p%op[i],k=i-1;
				if(!g)continue; //&&k
				while(g<op[k])--k,++o;
			}
			s=s*op[i]+p%op[i];
			dfs(s,d+1+o,i-1); //+n+1  +1+n
		}
	}
}

int main()
{
	n=read();
	while(n&&(n%10==2||n%10==3||n%10==7||n%10==8))++ans,n/=10;
	if(!n){
		puts("-1");
		exit(0);
	}
	k=sqrt(n+0.1);
	if(k*k==n){
		cout<<ans; 
		return 0;
	}

	op[1]=1;
	for(int i=2; i<=10; ++i)op[i]=op[i-1]*10;
	for(I=1; I<=9; ++I)
	{
	    dfs(n,0,0);
	    if(fl){
	    	cout<<I+ans;//()
		    return 0;
		}
	}
	puts("-1");
}