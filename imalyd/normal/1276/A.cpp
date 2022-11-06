//https://codeforces.com/contest/1276/problem/A
#include<bits/stdc++.h>
using namespace std;
char s[150005];int f[150005];
int main(){
	int t,x,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		n=strlen(s);x=0;
		for(i=0;i!=n;++i)f[i]=0;
		for(i=2;i< n;   ){
			if(s[i-2]=='o'&&s[i-1]=='n'&&s[i]=='e'){
				f[i-1]=1;
				i+=3;
			}else
			if(s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o'){
				if(i+2<n&&s[i+1]=='n'&&s[i+2]=='e'){f[i]=1;i+=5;}
				else{f[i-1]=1;i+=3;}
			}else ++i;
		}
		for(i=0;i!=n;++i)if(f[i])++x;
		printf("%d\n",x);
		for(i=0;i!=n;++i)if(f[i])printf("%d ",i+1);printf("\n");
	}
	return 0;
}