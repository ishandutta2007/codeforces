#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int A[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
char ch[1000];
int main(){
	int flag=0;
	for (int i=0;i<15;i++){
		printf("%d\n",A[i]);
		fflush(stdout);
		scanf("%s",ch+1);
		if (ch[1]=='y'){
			flag++;
			if (A[i]*A[i]<=100){
				printf("%d\n",A[i]*A[i]);
				fflush(stdout);
				scanf("%s",ch+1);
				if (ch[1]=='y'){
					flag++;
				}
			}
			if (flag>=2){
				printf("composite\n"); return 0;
			}
		}
	}
	printf("prime\n");
	return 0;
}