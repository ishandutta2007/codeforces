#include <cstdio>
#include <algorithm>

int stk[5001],top,d,P,pos[5001],tot;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int map[11][12],C[11][11],val[5001];
int Newpos(){return stk[top--];}
void Delpos(int x){stk[++top]=x;}
void add(int x,int y,int z){printf("+ %d %d %d\n",x,y,z);val[z]=add(val[x],val[y]);}
void pow(int x,int y){printf("^ %d %d\n",x,y);val[y]=qsm(val[x],d);}
void times(int x,int y){
//	printf("\t\t\ttimes %d %d %d\n",x,val[x],y);
	int tem=Newpos();
	while(y%2==0){
		add(x,x,x);
		y>>=1;
	}
	y>>=1;
	if(y)add(x,x,tem);
	while(y){
		if(y&1)add(x,tem,x);
		y>>=1;
		if(y)add(tem,tem,tem);
	}
	Delpos(tem);
//	printf("\t\t\t%d\n",val[x]);
}
void sqr(int x){
//	pow(x,x);
	pos[tot=0]=x;
	for(int i=1;i<=d;i++){
		pos[++tot]=Newpos();
		add(pos[tot-1],stk[1],pos[tot]);
	}
	for(int i=0;i<=d;i++)pow(pos[i],pos[i]);
	for(int i=0;i<=d;i++)times(pos[i],map[i][d+1]?map[i][d+1]:P);
	for(int i=1;i<=d;i++)add(pos[0],pos[i],pos[0]);
	for(int i=1;i<=d;i++)Delpos(pos[i]);
}
int main(){
	#ifdef ISONAN
	scanf("%d%d",val+1,val+2);
	for(int i=3;i<=5000;i++)val[i]=1;
	#endif
	for(int i=4;i<=5000;i++)stk[++top]=i;
	scanf("%d%d",&d,&P);
	for(int i=0;i<=d;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	for(int i=0;i<=d;i++){
		for(int j=0;j<=d;j++)
			map[i][j]=mul(C[d][i],qsm(j,d-i));
		map[i][d+1]=(i==2);
	}
//	for(int i=0;i<=d;i++,putchar('\n'))
//		for(int j=0;j<=d+1;j++)
//			printf("%d ",map[i][j]);
	for(int i=0;i<=d;i++){
		for(int j=i;j<=d;j++)
			if(map[j][i]){
				std::swap(map[i],map[j]);
				break;
			}
		for(int j=i+1;j<=d;j++)
			if(map[j][i]){
				int Mul=mul(qsm(map[i][i],P-2),map[j][i]);
				for(int k=0;k<=d+1;k++)
					map[j][k]=sub(map[j][k],mul(map[i][k],Mul));
			}
//	for(int i=0;i<=d;i++,putchar('\n'))
//		for(int j=0;j<=d+1;j++)
//			printf("%d ",map[i][j]);
	}
	for(int i=d;~i;--i)
		for(int j=i-1;~j;--j)
			if(map[j][i]){
				int Mul=mul(qsm(map[i][i],P-2),map[j][i]);
				for(int k=0;k<=d+1;k++)
					map[j][k]=sub(map[j][k],mul(map[i][k],Mul));
			}
	for(int i=0;i<=d;i++)map[i][d+1]=mul(map[i][d+1],qsm(map[i][i],P-2));
//	for(int i=0;i<=d;i++)printf("%d ",map[i][d+1]);putchar('\n');
	for(int i=0;i<=d;i++){
		int tot=0;
		for(int j=0;j<=d;j++)
			tot=add(tot,mul(map[j][d+1],mul(C[d][i],qsm(j,d-i))));
//		printf("%d\n",tot);
	}
	add(1,2,3);
	sqr(1);
	sqr(2);
	sqr(3);
	times(1,P-1);
	times(2,P-1);
	add(1,3,3);
	add(2,3,3);
	times(3,(P+1)>>1);
	printf("f 3\n");
	#ifdef ISONAN
	printf("%d\n",val[3]);
	#endif
}