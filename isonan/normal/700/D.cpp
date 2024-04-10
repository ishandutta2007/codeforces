#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

struct point{
	int l,r,orig;
}num[100001];
std::vector<int>vec;
std::priority_queue<int,std::vector<int>,std::greater<int> >heap;
int n,pos[100001],block,cnt[100001],a[100001],m,count[100001],tem[100001];
long long ans[100001];
bool cmp(point a,point b){return (pos[a.l]==pos[b.l])?(pos[a.l]&1?pos[a.r]<pos[b.r]:pos[a.r]>pos[b.r]):a.l<b.l;}
void add(int x){
	--count[cnt[a[x]]];
	++count[++cnt[a[x]]];
}
void del(int x){
	--count[cnt[a[x]]];
	++count[--cnt[a[x]]];
}
int main(){
	scanf("%d",&n);
	block=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		pos[i]=(i-1)/block+1;
		++count[a[i]];
		if(count[a[i]]==block)vec.push_back(a[i]);
	}
	memset(count,0,sizeof count);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&num[i].l,&num[i].r),num[i].orig=i;
	std::sort(num+1,num+m+1,cmp);
	for(int i=1,ql=1,qr=0;i<=m;i++){
		while(ql>num[i].l)add(--ql);
		while(qr<num[i].r)add(++qr);
		while(ql<num[i].l)del(ql++);
		while(qr>num[i].r)del(qr--);
		for(std::vector<int>::iterator it=vec.begin();it!=vec.end();++it)
			if(cnt[*it]>block)heap.push(cnt[*it]);
		int last=0;
		memcpy(tem,count,(block+1)<<2);
		for(int j=1;j<=block;++j){
			if(!tem[j])continue;
			if(last){
				ans[num[i].orig]+=last+j;
				--tem[j];
				if(last+j<=block)++tem[last+j];
				else heap.push(last+j);
				last=0;
			}
			if(tem[j]%2==1)last=j,--tem[j];
			ans[num[i].orig]+=(long long)tem[j]*j;
			if((j<<1)<=block)tem[j<<1]+=tem[j]>>1;
			else for(int k=1;k<=tem[j]>>1;k++)heap.push(j<<1);
		}
		if(last)heap.push(last);
		while(heap.size()>1){
			long long tem=heap.top();
			heap.pop();
			tem+=heap.top();
			heap.pop();
			ans[num[i].orig]+=tem;
			heap.push(tem);
		}
		if(heap.size()==1)heap.pop();
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}