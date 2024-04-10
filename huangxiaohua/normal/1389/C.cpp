#include<bits/stdc++.h>
using namespace std;
 
int i,j,t,n,num[10][200500],numn[10],tmp,res;
char sb[200500];

int chk(int a,int b){
	int i=1,j=1,tmp=0;
	while(i<=numn[a]&&j<=numn[b]){
		if(num[a][i]>num[b][j]){j++;continue;}
		if(num[a][i]<num[b][j]){tmp++;
			while(i<=numn[a]&&num[a][i]<num[b][j]){i++;}
			j++;continue;
		}
	}
	return tmp*2;
}

int main(){
	scanf("%d\n",&t);
	while(t--){
		memset(numn,0,sizeof(numn));
		gets(sb+1);
		n=strlen(sb+1);
		res=0;
		for(i=1;i<=n;i++){
			tmp=sb[i]-'0';
			numn[tmp]++;
			num[tmp][numn[tmp]]=i;
		}
		
		/*for(i=0;i<=9;i++){
			printf("%d\n",i);
			for(j=1;j<=numn[i];j++){
				printf("%d ",num[i][j]);
			}puts("");
		}*/
		
		for(i=0;i<=9;i++){
			res=max(res,numn[i]);
			for(j=0;j<=9;j++){
				if(i==j){continue;}
				res=max(res,chk(i,j));
				
				//printf("%d %d %d\n",i,j,chk(i,j));
			}
		}
		
		printf("%d\n",n-res);
	}
}