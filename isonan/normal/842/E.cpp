#include <cstdio>

int fa[300010][21],dep[300010],stk1[300010],top1,stk2[300010],top2,m,dia;
int LCA(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dist(int x,int y){return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);}
int main(){
	stk1[top1=dia=1]=1;
	scanf("%d",&m);
	for(int i=2,u;i<=m+1;i++){
		scanf("%d",&u);
		fa[i][0]=u;
		dep[i]=dep[u]+1;
		for(int j=1;j<=20;j++)fa[i][j]=fa[fa[i][j-1]][j-1];
		int d1=top1?dist(i,stk1[1]):0,d2=top2?dist(i,stk2[1]):0,d3=d1<d2?d2:d1;
		if(dia<d3){
			dia=d3;
			if(d1==d3){
				for(int j=1;j<=top2;j++)if(dist(i,stk2[j])==dia)stk1[++top1]=stk2[j];
				top2=0;
			}
			else{
				for(int j=1;j<=top1;j++)if(dist(i,stk1[j])==dia)stk2[++top2]=stk1[j];
				top1=0;
			}
		}
		if(dia==d3){
			if(d1==d3)stk2[++top2]=i;
			else stk1[++top1]=i;
		}
		#ifdef DEBUG
			printf("ans : ");
		#endif
		printf("%d\n",top1+top2);
	}
}