#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,a[100001],que[3][100001],orig[200001],top,cnt[200001];
int stk[100001],tot;
bool vis[100001];
std::vector<int>vec[100001],col[200001];
int root[200001],lson[6000001],rson[6000001],se[6000001],Cnt;
void add(int &pos,int l,int r,int e,int x){
	if(!pos)pos=++Cnt;
	se[pos]+=x;
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],l,(l+r)>>1,e,x);
	else add(rson[pos],((l+r)>>1)+1,r,e,x);
}
int query(int pos,int l,int r,int el,int er){
	if(el>r||er<l||!pos)return 0;
	if(el<=l&&er>=r)return se[pos];
	return query(lson[pos],l,(l+r)>>1,el,er)+query(rson[pos],((l+r)>>1)+1,r,el,er);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)orig[++top]=a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		for(int k=0;k<3;k++)que[k][i]=read();
		if(que[0][i]==1)orig[++top]=que[1][i];
	}
	std::sort(orig+1,orig+top+1);
	top=std::unique(orig+1,orig+top+1)-orig-1;
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(orig+1,orig+top+1,a[i])-orig;
	for(int i=1;i<=m;i++)
		if(que[0][i]==1)que[1][i]=std::lower_bound(orig+1,orig+top+1,que[1][i])-orig;
	for(int i=1;i<=n;i++)add(root[a[i]],1,n,i,1);
	int bl=(int)sqrt(m);
	for(int i=1;i<=m;i+=bl){
		int r=std::min(m,i+bl-1);
		tot=0;
		for(int j=i;j<=r;j++)
			if(que[0][j]==1){
				if(!vis[que[2][j]])stk[++tot]=que[2][j];
				vis[que[2][j]]=1;
			}
		for(int j=1;j<=top;j++)cnt[j]=0;
		for(int j=1;j<=n;j++)vec[j].clear();
		for(int j=1;j<=top;j++)col[j].clear();
		for(int j=1;j<=n;j++)if(!vis[j])vec[++cnt[a[j]]].push_back(j);
		for(int j=1;j<=n;j++)if(!vis[j])col[a[j]].push_back(j);
		for(int j=1;j<=top;j++)cnt[j]=0;
		for(int j=i;j<=r;j++)
			if(que[0][j]==1){
				add(root[a[que[2][j]]],1,n,que[2][j],-1);
				a[que[2][j]]=que[1][j];
				add(root[a[que[2][j]]],1,n,que[2][j],1);
			}
			else{
				if(que[1][j]==1)write(orig[a[que[2][j]]]);
				else{
					int p=que[2][j];
					int x=query(root[a[p]],1,n,1,p);
					if(que[1][j]%2==0)write(x);
					else{
						int ans=std::upper_bound(vec[x].begin(),vec[x].end(),p)-vec[x].begin();
						for(int k=1;k<=tot;k++){
							int y=stk[k];
//							printf("%d ",y);
							if(y>p)continue;
							if(x<=cnt[a[y]]||(col[a[y]].size()>=(x-cnt[a[y]])&&col[a[y]][x-cnt[a[y]]-1]<=p))--ans;
							++cnt[a[y]];
							if(x<=cnt[a[y]]||(col[a[y]].size()>=(x-cnt[a[y]])&&col[a[y]][x-cnt[a[y]]-1]<=p))++ans;
						}
//						printf("*%d\n",x);
						write(ans);
						for(int k=1;k<=tot;k++)cnt[a[stk[k]]]=0;
					}
				}
				putchar('\n');
			}
		for(int j=i;j<=r;j++)
			if(que[0][j]==1){
				vis[que[2][j]]=0;
			}
	}
}