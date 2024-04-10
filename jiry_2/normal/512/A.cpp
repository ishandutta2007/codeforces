#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[110],ans[110];
int b[30][30],A[110][110],pd[30],n,go[30];
int check(int k1,int k2){
	for (int i=1;i<=k2;i++) if (A[k1][i]!=A[k1-1][i]) return 0;
	return 1;
}
int main(){
	for (int i=1;i<=26;i++) b[i][0]=1;
	scanf("%d",&n); int m=0;
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1); m=max((int)(strlen(ch+1)),m);
		int k1=strlen(ch+1);
		for (int j=1;j<=k1;j++) A[i][j]=ch[j]-'a'+1;
	}
	for (int i=1;i<=m;i++)
		for (int j=2;j<=n;j++)
			if (check(j,i-1)&&A[j][i]!=A[j-1][i]){
				if (b[A[j][i]][A[j-1][i]]==0){
					b[A[j][i]][A[j-1][i]]=1; go[A[j-1][i]]++;
				}
			}
	for (int i=1;i<=26;i++){
		int where=0;
		for (int j=1;j<=26;j++) if (go[j]==0&&pd[j]==0) {where=j; break;}
		if (where==0){
			cout<<"Impossible"<<endl; return 0;
		}
		pd[where]=1; ans[i]='a'+where-1; 
		for (int j=1;j<=26;j++) if (b[where][j]) go[j]--;
	}
	for (int i=26;i;i--) putchar(ans[i]);
	return 0;
}