#include <cstdio>
#include <algorithm>

int n,Mx[2][100010],Mn[2][100010];
long long ans;
std::pair<int,int> vec[100001];
long long sqr(int x){
	return 1ll*x*x;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&vec[i].first,&vec[i].second);
	ans=1e18;
	int mx=-0x7f7f7f7f,mn=0x7f7f7f7f;
	for(int i=1;i<=n;i++)mx=std::max(mx,vec[i].first),mn=std::min(mn,vec[i].first);
	ans=std::min(ans,sqr(mx-mn));
	mx=-0x7f7f7f7f,mn=0x7f7f7f7f;
	for(int i=1;i<=n;i++)mx=std::max(mx,vec[i].second),mn=std::min(mn,vec[i].second);
	ans=std::min(ans,sqr(mx-mn));
	std::sort(vec+1,vec+n+1);
	Mx[0][0]=Mx[1][n+1]=-0x7f7f7f7f;
	Mn[0][0]=Mn[1][n+1]=0x7f7f7f7f;
	for(int i=1;i<=n;i++)Mx[0][i]=std::max(Mx[0][i-1],vec[i].second);
	for(int i=n;i;i--)Mx[1][i]=std::max(Mx[1][i+1],vec[i].second);
	for(int i=1;i<=n;i++)Mn[0][i]=std::min(Mn[0][i-1],vec[i].second);
	for(int i=n;i;i--)Mn[1][i]=std::min(Mn[1][i+1],vec[i].second);
	for(int i=1;i<=n;i++){
//		printf("%d\n",i);
		if(vec[i].first<0){
			int l=i,r=n-(i==1),mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(vec[mid].first>-vec[i].first){
					r=mid-1;
					continue;
				}
				int mn=std::min(Mn[0][i-1],Mn[1][mid+1]),mx=std::max(Mx[0][i-1],Mx[1][mid+1]);
				long long tem=0,tem2=0;
				tem=std::max(tem,sqr(vec[mid].first-vec[i].first));
				tem2=std::max(tem2,sqr(mx-mn));
				tem2=std::max(tem2,sqr(vec[i].first)+std::max(sqr(mn),sqr(mx)));
				::ans=std::min(::ans,std::max(tem,tem2));
//				printf("%d %d %d\n",mid,tem,tem2);
				if(tem<=tem2)l=mid+1;
				else r=mid-1;
			}
		}
		else{
			int l=1+(i==n),r=i,mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(-vec[mid].first>vec[i].first){
					l=mid+1;
					continue;
				}
				int mn=std::min(Mn[0][mid-1],Mn[1][i+1]),mx=std::max(Mx[0][mid-1],Mx[1][i+1]);
				long long tem=0,tem2=0;
				tem=std::max(tem,sqr(vec[mid].first-vec[i].first));
				tem2=std::max(tem2,sqr(mx-mn));
				tem2=std::max(tem2,sqr(vec[i].first)+std::max(sqr(mn),sqr(mx)));
				::ans=std::min(::ans,std::max(tem,tem2));
//				printf("%d %d %d\n",mid,tem,tem2);
				if(tem<=tem2)r=mid-1;
				else l=mid+1;
			}
		}
	}
	printf("%lld\n",ans);
}