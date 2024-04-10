#include<bits/stdc++.h>
using namespace std;
char sb[1055];
int i,j,zero,one,n,mx1,mx2,tmp;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",&sb);one=zero=mx1=mx2=0;
		for(j=1;j<=strlen(sb)+1;j++){
			if(sb[j-1]=='1'){one++;}
			if(sb[j-1]=='0'){zero++;}
		}
		mx1=tmp=zero;
		for(j=strlen(sb)+1;j>=1;j--){
			if(sb[j-1]=='0'){tmp--;}
			if(sb[j-1]=='1'){tmp++;}
			mx1=min(mx1,tmp);
		}
		one=zero=0;
		for(j=1;j<=strlen(sb)+1;j++){
			if(sb[j-1]=='0'){zero++;}
			if(sb[j-1]=='1'){one++;}
		}
		mx2=tmp=one;
		for(j=strlen(sb)+1;j>=1;j--){
			if(sb[j-1]=='1'){tmp--;}
			if(sb[j-1]=='0'){tmp++;}
			mx2=min(mx2,tmp);
		}
		mx1=min(mx1,mx2);
		printf("%d\n",mx1);
	}
}