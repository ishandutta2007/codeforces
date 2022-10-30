#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t,res,jj;
char sb[300500],stk[300500],stk2[300500];
int main(){
	scanf("%d",&t);getchar();
	while(t--){
		gets(sb+1);
		n=strlen(sb+1);
		for(i=1,j=1;i<=n;i++,j++){
			stk[j]=sb[i];
			if(stk[j]=='B'&&stk[j-1]=='A'){j-=2;}
		}j--;
		for(i=1,jj=1;i<=j;i++,jj++){
			stk2[jj]=stk[i];
			if(stk2[jj]=='B'&&stk2[jj-1]=='B'){jj-=2;}
		}jj--;
		printf("%d\n",jj);
	} 
}