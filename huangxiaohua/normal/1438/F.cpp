#include<bits/stdc++.h>
using namespace std;
struct sb{
	int a,id;
}s[300500];
bool cmp(sb s,sb b){
	return s.a>b.a;
}
int i,j,n,t,k,r1,r2,x,y,z;
 
int main(){
	scanf("%d",&n);
	n=(1<<n)-1;
	for(i=1;i<=n;i++){
		s[i].id=i;
	}
	srand(114514);
	for(i=1;i<=420;i++){
		x=(rand()<<16|rand())%n+1;
		y=(rand()<<16|rand())%n+1;
		z=(rand()<<16|rand())%n+1;
		if(x==y||y==z||x==z){i--;continue;}
		printf("? %d %d %d\n",x,y,z);
		fflush(stdout);
		scanf("%d",&k);
		s[k].a++;
		fflush(stdout);
	}
	sort(s+1,s+n+1,cmp);
	r1=s[1].id;r2=s[2].id;
	for(i=1;i<=n;i++){
		if(i==r1||i==r2){continue;}
		printf("? %d %d %d\n",r1,r2,i);
		fflush(stdout);
		scanf("%d",&k);
		fflush(stdout);
		if(k!=r1&&k!=r2){printf("! %d",k);return 0;}
	}
}