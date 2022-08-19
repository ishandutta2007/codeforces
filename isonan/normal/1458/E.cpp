#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

std::set<std::pair<int,int> >set,Ans[100001];
int cnt;
std::map<int,int>map;
int n,m,x[100001],y[100001],a[100001],b[100001];
void insert(int x,int y,int len){
//	printf("insert %d %d %d\n",x,y,len);
	if(len<0)return;
	if(!map.count(y-x))map[y-x]=cnt++;
	Ans[map[y-x]].insert(std::make_pair(x,x+len));
}
struct tree{
	int root[100001],lson[6000001],rson[6000001],cnt,mn[6000001];
	std::pair<int,int> num[100001];
	int orig[100001],Top;
	int top;
	void add(int &pos,int pre,int l,int r,int x){
		pos=++cnt;
		lson[pos]=lson[pre];
		rson[pos]=rson[pre];
		mn[pos]=std::min(mn[pre],orig[x]);
		if(l==r)return;
		if((l+r)>>1>=x)add(lson[pos],lson[pre],l,(l+r)>>1,x);
		else add(rson[pos],rson[pre],((l+r)>>1)+1,r,x);
	}
	int query(int pos,int l,int r,int el,int er){
		if(el>r||er<l||!pos)return 0x7f7f7f7f;
		if(el<=l&&er>=r)return mn[pos];
		return std::min(query(lson[pos],l,(l+r)>>1,el,er),query(rson[pos],((l+r)>>1)+1,r,el,er));
	}
	void add(int x,int y){
		std::swap(x,y);
		num[++top]=std::make_pair(x,y);
		orig[++Top]=y;
	}
	void build(){
		std::sort(num+1,num+top+1);
		std::sort(orig+1,orig+Top+1);
		Top=std::unique(orig+1,orig+Top+1)-orig-1;
		mn[0]=0x7f7f7f7f;
		for(int i=1;i<=top;i++){
			add(root[i],root[i-1],1,Top,std::lower_bound(orig+1,orig+Top+1,num[i].second)-orig);
		}
	}
	int get(int x,int y){
		int L=std::lower_bound(orig+1,orig+Top+1,x)-orig,R=std::upper_bound(num+1,num+top+1,std::make_pair(y-x,0x7f7f7f7f))-num-1;
		return query(root[R],1,Top,L,top);
	}
}X,Y;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i),
		X.add(x[i],y[i]-x[i]),
		Y.add(y[i],x[i]-y[i]),
		set.insert(std::make_pair(x[i],y[i]));
	X.build();
	Y.build();
	int x=0,y=0;
	for(;;){
		int nxtx=X.get(x,y),nxty=Y.get(y,x);
		int mn=std::min(nxtx-x,nxty-y);
		insert(x,y,mn-1);
//		printf("%d %d %d %d\n",x,y,nxtx,nxty);
		x+=mn,y+=mn;
		if(x==nxtx)++x;
		if(y==nxty)++y;
		if(nxtx==0x7f7f7f7f&&nxty==0x7f7f7f7f)break;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",a+i,b+i);
		bool ans=set.count(std::make_pair(a[i],b[i]));
		if(map.count(b[i]-a[i])){
			int x=map[b[i]-a[i]];
			auto now=Ans[x].upper_bound(std::make_pair(a[i],0x7f7f7f7f));
			if(now!=Ans[x].begin()){
				--now;
				if((now->second)>=a[i])ans=1;
			}
		}
		if(!ans)puts("WIN");
		else puts("LOSE");
	}
}