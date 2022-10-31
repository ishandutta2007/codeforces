#include<bits/stdc++.h>
using namespace std;

char sb[100500];
int t,a,i,j,one,zero,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d\n",&tmp);
		one=zero=tmp=0;
		gets(sb);
		i=strlen(sb);
		for(j=0;j<=i-2;j++){
			if(sb[j]=='1'&&sb[j+1]=='0'){tmp=1;break;}
		}
		for(j=0;j<=i-1;j++){
			if(sb[j]=='0'){zero++;}
			if(sb[j]=='1'){break;;}
		}
		for(j=i-1;j>=0;j--){
			if(sb[j]=='1'){one++;}
			if(sb[j]=='0'){break;;}
		}
		for(j=1;j<=zero;j++){
			printf("0");
		}
		if(tmp==1){printf("0");
		}
		for(j=1;j<=one;j++){
			printf("1");
		}puts("");
	}
	return 0;
}