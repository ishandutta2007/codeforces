
#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#define LL long long int
using namespace std;
char sb[200555];
int mx=0,i,j,k,n,k1,k2,k3,tmp,m;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",&sb);k1=k2=k3=0;mx=999999;m=strlen(sb);
		for(j=0;j<=m-1;j++){
			if(sb[j]=='1'){k1=1;}if(sb[j]=='2'){k2=1;}if(sb[j]=='3'){k3=1;}
		}
		if(k1+k2+k3!=3){printf("0\n");continue;}
		for(j=0;j<=m-3;j++){
			tmp=3;
			if(sb[j]=='1'&&sb[j+1]=='2'){
				for(k=j+2;sb[k]!='3';k++){tmp++;if(sb[k]=='1'){tmp=999999;break;}}
				mx=min(mx,tmp);
			}
			if(sb[j]=='1'&&sb[j+1]=='3'){
				for(k=j+2;sb[k]!='2';k++){tmp++;if(sb[k]=='1'){tmp=999999;break;}}
				mx=min(mx,tmp);
			}
			if(sb[j]=='3'&&sb[j+1]=='2'){
				for(k=j+2;sb[k]!='1';k++){tmp++;if(sb[k]=='3'){tmp=999999;break;}}
				mx=min(mx,tmp);
			}
			if(sb[j]=='2'&&sb[j+1]=='3'){
				for(k=j+2;sb[k]!='1';k++){tmp++;if(sb[k]=='2'){tmp=999999;break;}}
				mx=min(mx,tmp);
			}
			if(sb[j]=='3'&&sb[j+1]=='1'){
				for(k=j+2;sb[k]!='2';k++){tmp++;if(sb[k]=='3'){tmp=999999;break;}}
				mx=min(mx,tmp);
			}
			if(sb[j]=='2'&&sb[j+1]=='1'){
				for(k=j+2;sb[k]!='3';k++){tmp++;if(sb[k]=='2'){tmp=999999;break;}}
				mx=min(mx,tmp);
			}
		}
		printf("%d\n",mx);
	}
}