#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,l,res,jb[1000500],mx;
char sb[1000500];
int main(){
	scanf("%d\n",&n);
	while(n--){
		res=0;
		gets(sb);
		l=strlen(sb);jb[0]=0;mx=0;
		for(i=0;i<l;i++){
			if(sb[i]=='+'){jb[i+1]=jb[i]-1;}
			else{jb[i+1]=jb[i]+1;}
		}
		for(i=1;i<=l;i++){
			mx=max(mx,jb[i]);
			jb[i]=mx;
		}mx++;
		for(i=1;i<=l;i++){
			res+=(mx-jb[i]);
		}
		printf("%lld\n",res+mx-1);
	}
}