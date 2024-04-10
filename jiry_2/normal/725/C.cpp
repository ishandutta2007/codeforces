#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[1000],ans[2][100];
struct atom{
	int x,y;
}A[100];
void put(int k1,int k2){
	ans[A[k2].x][A[k2].y]=ch[k1];
}
int main(){
	scanf("%s",ch+1); int n=27;
	for (int i=1;i<n;i++) if (ch[i]==ch[i+1]){
		printf("Impossible\n"); return 0;
	}
	int l,r;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (ch[i]==ch[j]){
				l=i; r=j;
			}
	int L=(r-l)/2; int len=0;
	if ((r-l)&1) A[++len]=(atom){0,L+1};
	for (int i=L;i;i--) A[++len]=(atom){0,i};
	for (int i=1;i<=L;i++) A[++len]=(atom){1,i};
	if ((r-l&1)) A[++len]=(atom){1,L+1},L++;
	for (int i=L+1;i<=13;i++) A[++len]=(atom){1,i};
	for (int i=13;i>L;i--) A[++len]=(atom){0,i};
	len=0;
	for (int i=l;i<r;i++) put(i,++len);
	for (int i=l-1;i;i--) put(i,++len);
	for (int i=n;i>r;i--) put(i,++len);
	for (int i=0;i<2;i++){
		for (int j=1;j<=13;j++) putchar(ans[i][j]); putchar('\n');
	}
	return 0;
}