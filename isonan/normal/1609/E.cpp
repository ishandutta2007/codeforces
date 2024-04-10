#include <cstdio>
#include <cstring>
#include <algorithm>

int n,q;
char str[100001];
int se[1000001][3][3];
void pushup(int root){
	memset(se[root],0x3f,sizeof se[root]);
	for(int i=0;i<3;++i)
		for(int j=i;j<3;++j){
			for(int k=i;k<=j;++k){
				se[root][i][j]=std::min(se[root][i][j],se[root<<1][i][k]+se[root<<1|1][k][j]);
				if(k<j)se[root][i][j]=std::min(se[root][i][j],se[root<<1][i][k]+se[root<<1|1][k+1][j]);
			}
		}
}
void build(int root,int l,int r){
	if(l==r){
		memset(se[root],0x3f,sizeof se[root]);
		for(int i=0;i<3;++i)
			for(int j=i;j<3;++j)
				se[root][i][j]=(i==str[l]-'a'&&j==str[l]-'a');
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void update(int root,int l,int r,int e){
	if(l==r){
		memset(se[root],0x3f,sizeof se[root]);
		for(int i=0;i<3;++i)
			for(int j=i;j<3;++j)
				se[root][i][j]=(i==str[l]-'a'&&j==str[l]-'a');
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	pushup(root);
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",str+1);
	build(1,1,n);
	for(int i=1;i<=q;++i){
		int p;
		scanf("%d",&p);
		char ch=getchar();
		while(ch<'a'||ch>'c')ch=getchar();
		str[p]=ch;
		update(1,1,n,p);
		printf("%d\n",se[1][0][2]);
	}
}