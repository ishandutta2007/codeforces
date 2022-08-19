#include <cstdio>
#include <set>

using std::max;
using std::min;

int s[100010],m[100010],r[100010],n,q;
int lson[10000001],rson[10000001],root[100010],T[100010],R[100010];
long long sumM[10000001],sumR[10000001],cnt,ans;
std::set<int>set;
void add(int &pos,int pre,int l,int r,int e,int x,int y){
	pos=++cnt,lson[pos]=lson[pre],rson[pos]=rson[pre],sumM[pos]=sumM[pre]+x,sumR[pos]=sumR[pre]+y;
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],lson[pre],l,(l+r)>>1,e,x,y);
	else add(rson[pos],rson[pre],((l+r)>>1)+1,r,e,x,y);
}
long long queryright(int pos,int pre,int l,int r,int e){
	if(!pos)return 0;
	if(l>=e)return sumR[pos]-sumR[pre];
	if(r<e)return 0;
	return queryright(lson[pos],lson[pre],l,(l+r)>>1,e)+queryright(rson[pos],rson[pre],((l+r)>>1)+1,r,e);
}
long long queryleft(int pos,int pre,int l,int r,int e){
	if(!pos)return 0;
	if(r<=e)return sumM[pos]-sumM[pre];
	if(l>e)return 0;
	return queryleft(lson[pos],lson[pre],l,(l+r)>>1,e)+queryleft(rson[pos],rson[pre],((l+r)>>1)+1,r,e);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",s+i,m+i,r+i);
		if(r[i])add(root[i],root[i-1],0,100000,m[i]/r[i],m[i],r[i]);
		else root[i]=root[i-1];
		set.insert(i);
		T[i]=0;
	}
	scanf("%d",&q);
	set.insert(n+1);
	for(int i=1,t,l,r;i<=q;i++){
		scanf("%d%d%d",&t,&l,&r);
		long long ans=0;
		int a=-1,b=-1,L,t1,t2;
		for(auto x=--set.upper_bound(l);*x<=r&&x!=set.end();set.erase(L)){
			L=*x;
			t1=max(l,L);
			t2=min(r,*(++x)-1);
			if(!T[L])ans+=min((long long)::r[t1]*t+s[t1],(long long)m[t1]);
			else ans+=queryright(root[t2],root[t1-1],0,100000,t-T[L])*(t-T[L])+queryleft(root[t2],root[t1-1],0,100000,t-T[L]-1);
			if(t2<*x-1)T[r+1]=T[L],b=r+1;
			if(t1>L)a=L;
		}
		set.insert(l);
		if(~a)set.insert(a);
		if(~b)set.insert(b);
		T[l]=t;
		printf("%lld\n",ans);
	}
}