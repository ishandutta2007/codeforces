// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k;
int n,ans1[maxn],ans2[maxn],r1,r2;
char c=' ';
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void work1(int x,int y){
	int t=x+y;
	if (t==1+n){
		return;
	}
	printf("? %d %d %d %d\n",x+1,y,n,n); fflush(stdout);
	c=' '; while ((c<'A')||(c>'Z'))c=getchar();
	if (c=='Y'){
		r1++; ans1[r1]=1;
		while ((c>='A')&&(c<='Z'))c=getchar();
		work1(x+1,y);
	}
	else{
		r1++; ans1[r1]=2;
		while ((c>='A')&&(c<='Z'))c=getchar();
		work1(x,y+1);
	}
}
void work2(int x,int y){
	int t=x+y;
	if (t==1+n){
		return;
	}
	printf("? %d %d %d %d\n",1,1,x,y-1); fflush(stdout);
	c=' '; while ((c<'A')||(c>'Z'))c=getchar();
	if (c=='Y'){
		r2++; ans2[r2]=1;
		while ((c>='A')&&(c<='Z'))c=getchar();
		work2(x,y-1);
	}
	else{
		r2++; ans2[r2]=2;
		while ((c>='A')&&(c<='Z'))c=getchar();
		work2(x-1,y);
	}
}
int main(){
	n=read();
	work1(1,1);
	work2(n,n);
	printf("! ");
	for (i=1;i<=r1;i++){
		if (ans1[i]==1) printf("D"); else printf("R");
	}
	for (i=r2;i>=1;i--){
		if (ans2[i]==1) printf("R"); else printf("D");
	}
	printf("\n");
	return 0;
}