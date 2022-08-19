#include <bits/stdc++.h>

int r,c,n,cnt,x[300001],y[300001];
bool vis[3001][3001];
std::vector<int>se[3000001];
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		se[root].push_back(x);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int f[9000010],rank[9000010];
int stk[3][3000001],top;
int hash(int i,int j){return (i-1)*c+j;}
int Find(int x){return f[x]?f[x]=Find(f[x]):x;}
void Merge(int x,int y){
	x=Find(x),y=Find(y);
	if(x!=y)f[x]=y;
}
int find(int x){return f[x]?find(f[x]):x;}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(rank[x]>rank[y])std::swap(x,y);
	++top;
	stk[0][top]=rank[y];
	stk[1][top]=x;
	stk[2][top]=y;
	rank[y]=std::max(rank[y],rank[x]+1);
	f[x]=y;
}
void rollback(){
	rank[stk[2][top]]=stk[0][top];
	f[stk[1][top]]=0;
	--top;
}
void add(int i,int j,void(*Merge)(int,int)){
	if(i==1)Merge(hash(i,j),r*c+1);
	else if(!vis[i-1][j])Merge(hash(i,j),hash(i-1,j));
	if(i==r)Merge(hash(i,j),r*c+2);
	else if(!vis[i+1][j])Merge(hash(i,j),hash(i+1,j));
	if(!vis[i][j%c+1])Merge(hash(i,j),hash(i,j%c+1));
	if(!vis[i][(j==1)?c:(j-1)])Merge(hash(i,j),hash(i,(j==1)?c:(j-1)));
}
void solve(int root,int l,int r){
	int last=top;
	for(int i=0;i<se[root].size();i++){
		int x=::x[se[root][i]],y=::y[se[root][i]];
		vis[x][y]=0;
		add(x,y,merge);
	}
	if(l==r){
		if(find(::r*c+1)!=find(::r*c+2))
			add(1,1,n,l+1,n,l);
		else ++cnt;
	}
	else{
		solve(root<<1,l,(l+r)>>1);
		solve(root<<1|1,((l+r)>>1)+1,r);
	}
	for(int i=0;i<se[root].size();i++){
		int x=::x[se[root][i]],y=::y[se[root][i]];
		vis[x][y]=1;
	}
	while(last<top)rollback();
}
int main(){
	scanf("%d%d%d",&r,&c,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		vis[x[i]][y[i]]=1;
		add(1,1,n,1,i-1,i);
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(!vis[i][j])add(i,j,Merge);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			Find(hash(i,j));
	solve(1,1,n);
	printf("%d\n",cnt);
}