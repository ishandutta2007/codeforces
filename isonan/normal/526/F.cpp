#include <map>
#include <cstdio>
#include <algorithm>
#define pb push_back

int p[300001],n,mn[300001],mx[300001],num[300001],c[300001];
std::map<int,int>map1,map2;
std::vector<int>ql[900001],qr[900001],pl,pr;
bool cmp(const int &a,const int &b){return mn[a]>mn[b]||(mn[a]==mn[b]&&a<b);}
void update(int ind,int num){for(;ind;ind-=ind&-ind)c[ind]+=num;}
int query(int ind){int tot=0;for(;ind<=n;ind+=ind&-ind)tot+=c[ind];return tot;}
long long solve(int l,int r){
	if(l==r)return 1;
	int mid=(l+r)>>1;
	long long ans=solve(l,mid)+solve(mid+1,r);
	mn[mid+1]=mx[mid+1]=p[mid+1];
	for(int i=mid+2;i<=r;i++)mn[i]=std::min(mn[i-1],p[i]),mx[i]=std::max(mx[i-1],p[i]);
	mn[mid]=mx[mid]=p[mid];
	for(int i=mid-1;i>=l;i--)mn[i]=std::min(mn[i+1],p[i]),mx[i]=std::max(mx[i+1],p[i]);
	for(int i=mid+1,len;i<=r;i++)if((len=mx[i]-mn[i])>i-mid-1&&i-len>=l&&mx[i-len]<mx[i]&&mn[i-len]>mn[i])++ans;
	for(int i=mid,len;i>=l;i--)if((len=mx[i]-mn[i])>mid-i&&i+len<=r&&mx[i+len]<mx[i]&&mn[i+len]>mn[i])++ans;
	for(int i=l;i<=r;++i)
		if(i>mid)qr[mn[i]+i+n].pb(i),ql[mx[i]-i+n].pb(i),pr.pb(mn[i]+i+n),pl.pb(mx[i]-i+n);
		else     ql[mn[i]-i+n].pb(i),qr[mx[i]+i+n].pb(i),pl.pb(mn[i]-i+n),pr.pb(mx[i]+i+n);
	for(int i=0;i<pl.size();i++)
		#define x ql[pl[i]]
		if(!x.empty()){
			std::sort(x.begin(),x.end(),cmp);
			for(int j=0;j<x.size();j++)
				if(x[j]>mid)update(mx[x[j]],1);
				else ans+=query(mx[x[j]]);
			for(int j=0;j<x.size();j++)if(x[j]>mid)update(mx[x[j]],-1);
			x.clear();
		}
		#undef x
	for(int i=0;i<pr.size();i++)
		#define x qr[pr[i]]
		if(!x.empty()){
			std::sort(x.begin(),x.end(),cmp);
			for(int j=0;j<x.size();j++)
				if(x[j]<=mid)update(mx[x[j]],1);
				else ans+=query(mx[x[j]]);
			for(int j=0;j<x.size();j++)if(x[j]<=mid)update(mx[x[j]],-1);
			x.clear();
		}
		#undef x
	pl.clear(),pr.clear();
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;i++)scanf("%d%d",&u,&v),p[u]=v;
	printf("%I64d\n",solve(1,n));
}