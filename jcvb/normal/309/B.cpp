#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,r,c;
string str[1000005];
int l[1000005];
int nex[1000005][22];
int main()
{
	scanf("%d%d%d",&n,&r,&c);
	for (int i=1;i<=n;i++){
		cin>>str[i];
		l[i]=str[i].size();
	}
	int q=1;
	int sz=-1;
	for (int i=1;i<=n;sz-=1+l[i++]){
		if(q<i)sz=-1,q=i;
		while(q<=n && sz+1+l[q]<=c)sz+=1+l[q++];
		nex[i][0]=q;
	}
	nex[n+1][0]=n+1;
	for (int j=1;j<=21;j++)
		for (int i=1;i<=n+1;i++)
			nex[i][j]=nex[nex[i][j-1]][j-1];
	int ans=0,st;
	for (int i=1;i<=n;i++){
		int p=i;
		for (int j=0;j<=21;j++)if(1<<j&r)p=nex[p][j];
		if(p-i>ans){
			ans=p-i;
			st=i;
		}
	}
	if(ans){
		int e;
		for (int i=1;i<=r;i++){
			e=nex[st][0];
			for (int j=st;j<e;j++){
				if(j>st)putchar(' ');
				cout<<str[j];
			}
			st=e;printf("\n");
		}
	}
	return 0;
}