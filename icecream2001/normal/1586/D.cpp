#include<bits/stdc++.h>
#define LL long long
using namespace std;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
const LL P=1e6;
int n,m;
int tp=0;
int q[300],re[300],ans[300];
void MAIN(){
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		printf("?");
		for(int j=1;j<n;++j){
			printf(" %d",i);
		}
		printf(" %d",n);
		printf("\n");
		fflush(stdout);
		++tp;q[tp]=n-i;
		scanf("%d",&re[tp]);
	}
	for(int i=1;i<n;++i){
		printf("?");
		for(int j=1;j<n;++j){
			printf(" %d",n);
		}
		printf(" %d",i);
		printf("\n");
		fflush(stdout);
		++tp;q[tp]=i-n;
		scanf("%d",&re[tp]);
	}
	ans[n]=n;
	for(int i=1;i<=tp;++i){
		if(q[i]>0&&re[i]!=0) ans[n]--;
	}
	for(int i=1;i<=tp;++i){
		if(re[i]!=0) ans[re[i]]=ans[n]+q[i];
	}
	printf("!");
	for(int i=1;i<=n;++i) printf(" %d",ans[i]);
	printf("\n");
		fflush(stdout);
	return;
	//scanf("%d",&n);
} 

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
*/