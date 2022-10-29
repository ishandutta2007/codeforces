#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

char s[600001];
int l,n,i;
double f[600001],g[600001],ans;

int main(){
	scanf("%s",&s);
	l=strlen(s);
	n=(l+1)/2;
	f[n]=0;
	rep(i,n+1,l+1-n)
		f[n]+=1.0/i;
	rrep(i,n-1,1)
		f[i]=f[i+1]+1.0/(i+1)+1.0/(l+1-i);
	g[1]=0;
	rep(i,2,n)
		g[i]=g[i-1]+(i-1)/1.0/(l+2-i);
	ans=0;
	/*
	rep(i,1,l)
		cout<<f[i]<<' ';
	cout<<endl;
	rep(i,1,l)
		cout<<g[i]<<' ';
	cout<<endl;
	*/
	rep(i,1,l)
		if ((s[i-1]=='I')||(s[i-1]=='E')||(s[i-1]=='A')||(s[i-1]=='O')||(s[i-1]=='U')||(s[i-1]=='Y'))
			{
				if (i<l+1-i){
					ans+=i+i*f[i]+g[i];
				}
				else{
					ans+=(l+1-i)*(1+f[l+1-i])+g[l+1-i];
				}
			}
	printf("%.8f",ans);
	return 0;
}