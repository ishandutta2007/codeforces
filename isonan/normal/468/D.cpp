#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

int head[100001],nxt[200001],b[200001],v[200001],k,n,size[100001],mx[100001],root,bel[100001],now[100001];
long long ans;
int res[100001];
std::priority_queue<int,std::vector<int>,std::greater<int> >heap;
std::vector<int>ord[200001];
std::set<int>exi[100001];
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getroot(b[i],x),size[x]+=size[b[i]],mx[x]=std::max(mx[x],size[b[i]]);
	mx[x]=std::max(mx[x],n-size[x]);
	if(mx[x]<mx[root])root=x;
}
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getdis(int x,int f,int rt,long long dis){
	ord[bel[x]=rt].push_back(x);
	++size[bel[x]];
	ans+=dis;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getdis(b[i],x,(rt==root)?b[i]:rt,dis+v[i]);
}
int main(){
//	freopen("CF468D.in","r",stdin);
//	freopen("CF468D.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,s,t,val;i<n;i++){
		scanf("%d%d%d",&s,&t,&val);
		push(s,t,val);
		push(t,s,val);
	}
	mx[root=0]=n;
	getroot(1,0);
	memset(size,0,sizeof size);
	getdis(root,0,root,0);
	printf("%I64d\n",ans<<1);
	for(int i=1;i<=n;i++)
		if(bel[i]==i){
			std::sort(ord[i].begin(),ord[i].end());
			heap.push(ord[i][0]);
			exi[size[i]<<=1].insert(i);
		}
	for(int i=1;i<=n;i++){
		int b=bel[i];
		exi[size[b]].erase(b);
		--size[b];
		exi[size[b]].insert(b);
		if(exi[n-i+1].size()&&(*exi[n-i+1].begin()!=root)){
			int tem=*exi[n-i+1].begin(),tem2=ord[tem][now[tem]];
			--size[tem];
			printf("%d ",tem2);
			exi[n-i].insert(tem);
			if(ord[tem].size()>(++now[tem]))heap.push(ord[tem][now[tem]]);
		}
		else{
			int tem=0x7f7f7f7f;
			for(;heap.size();){
				tem=heap.top();
				heap.pop();
				if(tem==ord[bel[tem]][now[bel[tem]]]&&bel[tem]!=b)break;
			}
			if(i==root&&now[root]==0&&root<tem){
				heap.push(tem);
				printf("%d ",root);
				exi[size[root]].erase(root);
				--size[root];
				exi[size[root]].insert(root);
				heap.pop();
				continue;
			}
			if(ord[b].size()>now[b])heap.push(ord[b][now[b]]);
			exi[size[bel[tem]]].erase(bel[tem]);
			--size[bel[tem]];
			exi[size[bel[tem]]].insert(bel[tem]);
			printf("%d ",tem);
			if(ord[bel[tem]].size()>(++now[bel[tem]]))heap.push(ord[bel[tem]][now[bel[tem]]]);
		}
	}
}