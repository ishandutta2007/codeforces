#include <cstdio>
#include <vector>
#include <cstring>
#include <set>

int t;
char a[200010];
struct point{int tst,t,lst,l,rst,r,sum;char L,R;}se[1000001];
point merge(point a,point b){
	if(!a.sum)return b;
	if(!b.sum)return a;
	point c=a;
	if(b.L!=a.R&&c.t<a.r+b.l)c.t=a.r+b.l,c.tst=a.rst;
	if(c.t<b.t)c.t=b.t,c.tst=b.tst;
	if(b.r==b.sum&&b.L!=a.R)c.rst=a.rst,c.r=b.r+a.r;
	else c.rst=b.rst,c.r=b.r;
	if(a.l==a.sum&&b.L!=a.R)c.lst=b.lst,c.l=b.l+a.l;
	c.sum+=b.sum;
	c.R=b.R;
	return c;
}
void build(int root,int l,int r){
	if(l==r){
		se[root]=(point){l,1,l,1,l,1,1,a[l],a[l]};
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=merge(se[root<<1],se[root<<1|1]);
//	printf("%d %d %d %d %c %c\n",root,l,r,se[root].t,se[root].L,se[root].R);
}
void update(int root,int l,int r,int e){
	if(l==r){
		se[root].sum=0;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=merge(se[root<<1],se[root<<1|1]);
//	printf("%d %d %d %d %d %d\n",root,l,r,se[root].sum,se[root<<1].sum,se[root<<1|1].sum);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root].sum;
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
point get(int root,int l,int r,int el,int er){
	if(el<=l&&er>=r)return se[root];
	if(el>((l+r)>>1))return get(root<<1|1,((l+r)>>1)+1,r,el,er);
	else if(er<=((l+r)>>1))return get(root<<1,l,(l+r)>>1,el,er);
	return merge(get(root<<1,l,(l+r)>>1,el,er),get(root<<1|1,((l+r)>>1)+1,r,el,er));
}
std::vector<std::pair<int,int> >ans;
std::set<int>set,good,Do[26];
int nl,cnt[26];
void solve(int pos,int r){
	Do[a[pos]-'a'].erase(pos);
	Do[a[r]-'a'].erase(r+1);
	--cnt[a[pos]-'a'];
	--cnt[a[r]-'a'];
	good.erase(pos);
	good.erase(r+1);
	int x=query(1,1,nl,1,pos),cnt=query(1,1,nl,1,r)-x+1;
	for(int j=1;j<=cnt;j++){
		int v=*set.lower_bound(pos);
//				printf("del %d\n",v);
		update(1,1,nl,v);
		set.erase(v);
	}
	std::set<int>::iterator now=set.upper_bound(pos);
	ans.push_back(std::make_pair(x,x+cnt-1));
}
int stk[200010],top;
bool vis[200010];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("my.out","w",stdout);
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%s",a+1);
		nl=strlen(a+1);
		build(1,1,nl);
		for(int i=1;i<=nl;i++)vis[i]=0;
		for(int i=0;i<26;i++)Do[i].clear();
		set.clear();
		ans.clear();
		good.clear();
		for(int i=1;i<=nl;i++)set.insert(i);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=2;i<=nl;i++)if(a[i]==a[i-1])++cnt[a[i]-'a'],good.insert(i),Do[a[i]-'a'].insert(i);
//		if(fd%1000==0)fprintf(stderr,"%d\n",fd);
		for(int mx=0;;){
			mx=0;
			for(int i=0;i<26;i++)if(cnt[i]>cnt[mx])mx=i;
			if(cnt[mx]==good.size())break;
//			for(int i=0;i<26;i++)printf("%d ",cnt[i]);printf("%d %d\n",mx,good.size());
			if(a[*good.begin()]-'a'==mx){
				int p=nl+1;
				for(int j=0;j<26;j++)if(j!=mx&&Do[j].size())p=std::min(p,*Do[j].begin());
				solve(*--good.lower_bound(p),p-1);
			}
			else solve(*--good.lower_bound(*Do[mx].begin()),*Do[mx].begin()-1);
		}
		while(se[1].sum){
			int pos=se[1].tst,cnt=se[1].t,x=query(1,1,nl,1,pos);
//			printf("%d %d %d\n",pos,cnt,x);
			for(int j=1;j<=cnt;j++){
				int v=*set.lower_bound(pos);
//				printf("del %d\n",v);
				update(1,1,nl,v);
				set.erase(v);
			}
			ans.push_back(std::make_pair(x,x+cnt-1));
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
}