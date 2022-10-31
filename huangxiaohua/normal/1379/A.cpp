#include<bits/stdc++.h>
using namespace std;
 
int t,n,i,j,no,yes,num,k;
char sb[66],chk[9]="xabacaba";
 
int chknum(char sb[66],int n,int k){
	int num=0,i,j,no;
	char jb[106];
	strcpy(jb+1,sb+1);
	for(i=k;i<=k+6;i++){
				if(jb[i]=='?'){jb[i]=chk[i-k+1];}
		}
	for(i=1;i<=n-6;i++){
		no=0;
		for(j=i;j<=i+6;j++){
			if(jb[j]==chk[j-i+1]){continue;}
			else{no=1;break;}
		}
		if(no==0){
			num++;
		}
		}
	
	return num;
}
 
int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d\n",&n);yes=num=k=0;
		gets(sb+1);
		if(chknum(sb,n,88)==1){num=1;goto aaa;}
		if(chknum(sb,n,88)>1){puts("no");continue;}
		for(i=1;i<=n-6;i++){
			no=0;
			for(j=i;j<=i+6;j++){
				if(sb[j]==chk[j-i+1]||sb[j]=='?'){continue;}
				else{no=1;break;}
			}
			if(no==0){
				if(chknum(sb,n,i)==1){yes=1;k=i;break;}
			}
		}
		aaa:if(num==1){
			puts("yes");
			for(i=1;i<=n;i++){
				if(sb[i]=='?'){sb[i]='z';}
			}
			puts(sb+1);continue;
		}
		if(num==0&&yes==1){
			puts("yes");
			for(i=k;i<=k+6;i++){
				if(sb[i]=='?'){sb[i]=chk[i-k+1];}
			}
			for(i=1;i<=n;i++){
				if(sb[i]=='?'){sb[i]='z';}
			}
			puts(sb+1);continue;
		}
		else{puts("no");
		}
	}
}