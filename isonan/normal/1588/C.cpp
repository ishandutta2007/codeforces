#include <cstdio>
#include <map>

int t,a[300001],n;
long long S[300001];
struct ST{ 
	long long st[300001][21];
	int Log[300001];
	long long query(int l,int r){
		int k=Log[r-l+1];
		return std::min(st[l][k],st[r-(1<<k)+1][k]);
	}
	void init(){
		for(int i=2;i<=n;++i)Log[i]=Log[i>>1]+1;
		for(int j=1;(1<<j)<=n;++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
}s[2];
std::map<long long,int>map;
int lson[8000001],rson[8000001],siz[8000001],cnt;
int query(int &pos,int l,int r,int el,int er){
	if(el>r||er<l||!pos)return 0;
	if(el<=l&&er>=r)return siz[pos];
	return query(lson[pos],l,(l+r)>>1,el,er)+query(rson[pos],((l+r)>>1)+1,r,el,er);
}
void add(int &pos,int l,int r,int e){
	if(!pos){
		pos=++cnt;
		lson[pos]=rson[pos]=siz[pos]=0;
	}
	++siz[pos];
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],l,(l+r)>>1,e);
	else add(rson[pos],((l+r)>>1)+1,r,e);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		map.clear();
		cnt=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			S[i]=1ll*a[i]-S[i-1];
			s[i&1].st[i][0]=S[i];
			s[(i&1)^1].st[i][0]=1e18;
			add(map[S[i]*((i&1)?-1:1)],1,n,i);
		}
		s[0].init();
		s[1].init();
		long long tot=0;
		for(int i=n-1;~i;--i){
			int l=i+1,r=n,mid,ans=-1;
			while(l<=r){
				mid=(l+r)>>1;
				if(s[i&1].query(i+1,mid)>=S[i]&&s[(i&1)^1].query(i+1,mid)>=-S[i])ans=mid,l=mid+1;
				else r=mid-1;
			}
			tot+=query(map[S[i]*((i&1)?-1:1)],1,n,i+1,ans);
		}
		printf("%lld\n",tot);
	}
}