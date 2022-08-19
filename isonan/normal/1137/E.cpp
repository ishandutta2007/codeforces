#include <cstdio>
#define int long long

long long stk[300001][3],top=1,n,m,best=1,nownum,K,B;
long long eval(long long x){
	return (K+stk[x][0])*stk[x][2]+B+stk[x][1];
}
double intersect(int x,int y){
	return (double)(stk[x][0]-stk[y][0])/(stk[y][1]-stk[x][1]);
}
bool comp(int x){
	return eval(top)*(stk[top][2]-stk[top-1][2])>=(eval(top-1)-eval(top))*(x-stk[top][2]);
}
signed main(){
	scanf("%I64d%I64d",&nownum,&m);
	--nownum;
	for(int i=1,opt,k,b,s;i<=m;i++){
		scanf("%I64d",&opt);
		if(opt==1){
			scanf("%I64d",&k);
			top=1;
			K=B=0;
			stk[top][0]=0;
			stk[top][1]=0;
			stk[top][2]=0;
			nownum+=k;
		}
		else if(opt==2){
			scanf("%I64d",&k);
			if(eval(top)==0){
				nownum+=k;
				goto loop;
			}
			while(top>1&&comp(nownum+1))--top;
			++top;
			stk[top][0]=-K;
			stk[top][1]=-B;
			stk[top][2]=nownum+1;
			nownum+=k;
		}
		else{
			scanf("%I64d%I64d",&b,&s);
			K+=s;
			B+=b;
			while(top>1&&eval(top-1)<=eval(top))--top;
		}
		loop:
//		putchar('*');
		printf("%I64d %I64d\n",stk[top][2]+1,eval(top));
//		for(int i=1;i<top;i++)printf("%.3lf ",intersect(i,i+1));putchar('\n');
//		for(int i=1;i<=top;i++)printf("(%I64d %I64d %I64d %I64d)",K+stk[i][0],B+stk[i][1],stk[i][2],eval(i));putchar('\n');
	}
}