#include <cstdio>
#include <vector>
#include <algorithm>

using std::min;
using std::max;

int f[100001],n,cnt,L[100001],R[100001],Ol[100001],Or[100001],orig[200001],top;
int query[100001][3];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
std::vector<int>vec[800001];
void merge(int root,int l,int r,int e,int x){
	for(auto it=vec[root].begin();it!=vec[root].end();++it){
		int tem=find(*it);
		if(tem==x)continue;
		f[tem]=x;
		L[x]=min(L[x],L[tem]);
		R[x]=max(R[x],R[tem]);
	}
	if(!vec[root].empty())vec[root].clear(),vec[root].push_back(x);
	if(l==r)return;
	if((l+r)>>1>=e)merge(root<<1,l,(l+r)>>1,e,x);
	else merge(root<<1|1,((l+r)>>1)+1,r,e,x);
}
void add(int root,int l,int r,int el,int er,int x){
	if(el>er)return;
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		vec[root].push_back(x);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&query[i][0],&query[i][1],&query[i][2]);
		if(query[i][0]==1)orig[++top]=query[i][1],orig[++top]=query[i][2]; 
	}
	std::sort(orig+1,orig+top+1);
	top=std::unique(orig+1,orig+top+1)-orig-1;
	for(int i=1,x,y;i<=n;i++){
		if(query[i][0]==1){
			++cnt;
			x=std::lower_bound(orig+1,orig+top+1,query[i][1])-orig;
			y=std::lower_bound(orig+1,orig+top+1,query[i][2])-orig;
			L[cnt]=Ol[cnt]=x,R[cnt]=Or[cnt]=y;
			merge(1,1,top,x,cnt);
			merge(1,1,top,y,cnt);
			add(1,1,top,L[cnt]+1,R[cnt]-1,cnt);
		}
		else{
			y=find(query[i][2]);
			x=query[i][1];
			if(find(x)==y||(L[y]<Ol[x]&&R[y]>Ol[x])||(L[y]<Or[x]&&R[y]>Or[x]))puts("YES");
			else puts("NO");
		}
	}
}