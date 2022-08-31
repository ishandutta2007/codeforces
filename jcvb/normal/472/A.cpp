#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int pr[1000005],bo[1000005]={0},tot=0;
void sieve(int n){
	for (int i=2;i<=n;i++){
		if(!bo[i])pr[++tot]=i;
		for (int j=1;j<=tot && pr[j]*i<=n;j++){
			bo[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
}
int main()
{
    sieve(1000000);
    int n;scanf("%d",&n);
    for (int i=4;;i++)
        if(bo[i] && bo[n-i]){
                 printf("%d %d\n",i,n-i);
                 return 0;
        
}}