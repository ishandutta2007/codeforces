#include<bits/stdc++.h>
using namespace std;
int n,i,j,l,res;
char sb[666],jb[666];
int main(){
	scanf("%d\n",&n);
	while(n--){
		res=0;
		gets(sb);
		l=strlen(sb);
		j=0;
		for(i=0;i<l;i++,j++){
			jb[j]=sb[i];
			if(j>0&&jb[j]!=jb[j-1]){j-=2;res++;}
		}
		if(res%2==0){puts("NET");}
		else{puts("DA");}
	}
}