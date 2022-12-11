#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[100];
int num,n;
const int lim=20000;
int main(){
	scanf("%d",&n);
	int now=0;
	for (;n;n--){
		int k1; scanf("%d",&k1); scanf("%s",ch+1); 
		if (now==0&&ch[1]!='S'){
			printf("No\n"); return 0;
		}
		if (now==lim&&ch[1]!='N'){
			printf("No\n"); return 0;
		}
		if (ch[1]=='S'){
			now+=k1; 
			if (now>lim){
				printf("No\n"); return 0;
			}
		} else if (ch[1]=='N'){
			now-=k1;
			if (now<0){
				printf("No\n"); return 0;
			}
		}
	}
	if (now!=0) printf("No\n"); else 
	printf("Yes\n"); return 0;
}