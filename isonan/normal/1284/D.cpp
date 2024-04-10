#include <cstdio>
#include <queue>
#include <algorithm>

int n;
struct point{
	int sa,ea,sb,eb;
}num[200001];
bool cmp1(point a,point b){return a.sa<b.sa;}
bool cmp2(point a,point b){return a.sb<b.sb;}
std::priority_queue<std::pair<int,int> >heap;
int orig[2][400001],lim[2];
int se[2000001];
void update(int root,int l,int r,int e,int x){
	se[root]=std::max(se[root],x);
	if(l==r)return;
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
}
void build(int root,int l,int r){
	se[root]=-1;
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return -1;
	if(el<=l&&er>=r)return se[root];
	return std::max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&num[i].sa,&num[i].ea,&num[i].sb,&num[i].eb);
	for(int i=1;i<=n;i++)orig[0][(i<<1)-1]=num[i].sa,orig[0][i<<1]=num[i].ea;
	std::sort(orig[0]+1,orig[0]+(n<<1)+1);
	lim[0]=std::unique(orig[0]+1,orig[0]+(n<<1)+1)-orig[0]-1;
	for(int i=1;i<=n;i++)
		num[i].sa=std::lower_bound(orig[0]+1,orig[0]+lim[0]+1,num[i].sa)-orig[0],
		num[i].ea=std::lower_bound(orig[0]+1,orig[0]+lim[0]+1,num[i].ea)-orig[0];
	for(int i=1;i<=n;i++)orig[1][(i<<1)-1]=num[i].sb,orig[1][i<<1]=num[i].eb;
	std::sort(orig[1]+1,orig[1]+(n<<1)+1);
	lim[1]=std::unique(orig[1]+1,orig[1]+(n<<1)+1)-orig[1]-1;
	for(int i=1;i<=n;i++)
		num[i].sb=std::lower_bound(orig[1]+1,orig[1]+lim[1]+1,num[i].sb)-orig[1],
		num[i].eb=std::lower_bound(orig[1]+1,orig[1]+lim[1]+1,num[i].eb)-orig[1];
	std::sort(num+1,num+n+1,cmp1);
	build(1,1,lim[1]);
	bool cando=1;
	for(int i=1;i<=n;i++){
		while(!heap.empty()&&-heap.top().first<num[i].sa){
			int now=heap.top().second;
			heap.pop();
			update(1,1,lim[1],num[now].sb,num[now].eb);
		}
		if(query(1,1,lim[1],1,num[i].eb)>=num[i].sb){
			cando=0;
			break;
		}
		heap.push(std::make_pair(-num[i].ea,i));
	}
	while(!heap.empty())heap.pop();
	std::sort(num+1,num+n+1,cmp2);
	build(1,1,lim[0]);
	for(int i=1;i<=n;i++){
		while(!heap.empty()&&-heap.top().first<num[i].sb){
			int now=heap.top().second;
			heap.pop();
			update(1,1,lim[0],num[now].sa,num[now].ea);
		}
		if(query(1,1,lim[0],1,num[i].ea)>=num[i].sa){
			cando=0;
			break;
		}
		heap.push(std::make_pair(-num[i].eb,i));
	}
	if(!cando)puts("NO");
	else puts("YES");
}