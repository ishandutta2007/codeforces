#include<bits/stdc++.h>
using namespace std;
int n,i,j,x,y,sb[50][50],res,zero[666],one[666],len;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		res=0;
		memset(zero,0,500);
		memset(one,0,500);
		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				scanf("%d",&sb[i][j]);
				if(sb[i][j]==0){zero[i+j-1]++;}
				else{one[i+j-1]++;}
			}
		}
		len=x+y-1;
		for(i=1;i<=len/2;i++){
			one[i]+=one[len+1-i];
			zero[i]+=zero[len+1-i];
			res+=min(one[i],zero[i]);
		}
		printf("%d\n",res);
	}
}