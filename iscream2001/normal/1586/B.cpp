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
int a[100005];
void MAIN(){
	int sum=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;++i) {
		a[i]=0;
	}
	int u,v,w;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		a[v]=1;
	}
	int rt=0;
	for(int i=1;i<=n;++i) if(a[i]==0) rt=i;
	for(int i=1;i<=n;++i){
		if(i!=rt){
			printf("%d %d\n",rt,i);
		}
	}

	return;
	//scanf("%d",&n);
} 

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
*/