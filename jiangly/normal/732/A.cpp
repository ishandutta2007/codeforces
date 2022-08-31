#include<bits/stdc++.h>
int k,r;
int main(){
	scanf("%d%d",&k,&r);
	for(int i=1;;++i)
		if(i*k%10==0||i*k%10==r){
			printf("%d\n",i);
			break;
		}
	return 0;
}