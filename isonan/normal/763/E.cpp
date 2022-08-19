#include <cstdio>
#include <vector>
#include <algorithm>

int n,k,m,l[100001],r[100001],q;
int bef[100001][6],ans[100001];
struct dsu{
	int f[100001],tag[100001],now;
	void clear(){
		++now;
	}
	int find(int x){
		if(tag[x]<now)tag[x]=now,f[x]=0;
		return f[x]?f[x]=find(f[x]):x;
	}
}a;
int g[100001][6],val[100001],tem1[6],tem2[6];
std::vector<int>que;
void solve(int l,int r,std::vector<int>que){
	if(l==r){
		for(int i=0;i<que.size();++i)ans[que[i]]=1;
		return;
	}
	int mid=(l+r)>>1;
	std::vector<int>L,R;
	a.clear();
	for(int i=mid;i>=l;i--){
		val[i]=((i==mid)?0:val[i+1])+1;
		for(int j=1;j<=k;j++)
			if(i+j<=mid&&bef[i][j]){
				int u=a.find(i),v=a.find(i+j);
				if(u!=v){
					a.f[u]=v;
					--val[i];
				}
			}
		for(int j=1;j<=k;j++)
			if(mid-j+1>=i)g[i][j]=a.find(mid-j+1);
			else g[i][j]=-1;
	}
	for(int i=mid+1;i<=r;i++){
		val[i]=((i==mid+1)?0:val[i-1])+1;
		for(int j=1;j<=k;j++)
			if(i-j>mid&&bef[i-j][j]){
				int u=a.find(i),v=a.find(i-j);
				if(u!=v){
					a.f[u]=v;
					--val[i];
				}
			}
		for(int j=1;j<=k;j++)
			if(mid+j<=i)g[i][j]=a.find(mid+j);
			else g[i][j]=-1;
	}
	for(int i=0;i<que.size();++i)
		if(::r[que[i]]<=mid)L.push_back(que[i]);
		else if(::l[que[i]]>mid)R.push_back(que[i]);
		else{
			int l=::l[que[i]],r=::r[que[i]];
			ans[que[i]]=val[l]+val[r];
			memcpy(tem1,g[l],sizeof tem1);
			memcpy(tem2,g[r],sizeof tem2);
			for(int j=1;j<=k;j++)
				for(int y=1;y+j-1<=k;y++)
					if(mid-j+1>=l&&mid+y<=r&&bef[mid-j+1][y+j-1]&&tem1[j]!=tem2[y]){
//						printf("^%d %d\n",j,y);
						int u=tem1[j],v=tem2[y];
						for(int m=1;m<=k;m++)if(tem2[m]==v)tem2[m]=u;
						for(int m=1;m<=k;m++)if(tem1[m]==v)tem1[m]=u;
						--ans[que[i]];
					}
		}
	solve(l,mid,L);
	solve(mid+1,r,R);
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(u>v)std::swap(u,v);
		bef[u][v-u]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",l+i,r+i);
		que.push_back(i);
	}
	solve(1,n,que);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}