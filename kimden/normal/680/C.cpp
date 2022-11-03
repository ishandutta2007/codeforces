#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[4];
	int b = 0;
	char s[20];
	int p[4] = {2,3,5,7};
	int pp[11]={11,13,17,19,23,29,31,37,41,43,47};
	for(int i=0;i<4;i++){
		printf("%d\n",p[i]);
		fflush(stdout);
		scanf("%s",&s);
		if(strcmp(s,"yes")==0){
			a[i] = 1;
		}else{
			a[i] = 0;
		}
		b += a[i];
	}
	if(b==0){
		printf("prime");
		fflush(stdout);
		return 0;
	}
	if(b>=2){
		printf("composite");
		fflush(stdout);
		return 0;
	}
	int n=0;
	while(a[n]==0){
		n++;
	}
	printf("%d\n",p[n]*p[n]);
	fflush(stdout);
	scanf("%s",&s);
	if(strcmp(s,"yes")==0){
		printf("composite");
		fflush(stdout);
		return 0;
	}else{
		for(int j=0;j<11;j++){
			printf("%d\n",pp[j]);
			fflush(stdout);
			scanf("%s",&s);
			if(strcmp(s,"yes")==0){
				printf("composite");
				fflush(stdout);
				return 0;
			}
		}
		printf("prime");
		fflush(stdout);
		return 0;
	}
}