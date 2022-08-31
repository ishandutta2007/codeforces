#include <cstdio>
#include <algorithm> 

int se[4000001],mn[4000001],lazy[4000001];
int n,dfn[400001],p[400001],val[400001],top,stack[400001],lson[400001],rson[400001],now;
int mx[400001];
void dfs(int x,int f){
	if(!x)return;
	dfn[x]=++now;
	dfs(lson[x],x);
	dfs(rson[x],x);
	mx[x]=now;
}
void spread(int x){
	mn[x]+=lazy[x];
	lazy[x<<1]+=lazy[x];
	lazy[x<<1|1]+=lazy[x];
	lazy[x]=0;
}
void update(int root,int l,int r,int el,int er,int x){
	spread(root);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		lazy[root]+=x;
		spread(root);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	mn[root]=std::max(mn[root<<1],mn[root<<1|1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for (int i=1;i<=n<<1;i++){
        val[i]=p[(i>n)?(i-n):i];
        while (top&&val[i]<=val[stack[top]]){
            lson[i]=stack[top];
            top--;
        }
        if(top)rson[stack[top]]=i;
        stack[++top]=i;
    }
    dfs(stack[1],0);
    for(int i=1;i<=n;i++)update(1,1,n<<1,dfn[i],mx[i],1);
    int ans=n+1,p=0;
    for(int i=n+1;i<=n<<1;i++){
    	if(ans>mn[1])ans=mn[1],p=i-n-1;
    	update(1,1,n<<1,dfn[i-n],mx[i-n],-1);
    	update(1,1,n<<1,dfn[i],mx[i],1);
	}
	printf("%d %d\n",ans,p);
}