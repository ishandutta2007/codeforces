#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int low[100010],a[100010],s[100010],n,m,prev[100010],f[100010],end[100010],pos,top,cnt[100010];
std::multiset<int>set;
int find(int x){
	return std::upper_bound(s+1,s+m+1,x)-s-1;
}
int main(){
//	freopen("CF568E.in","r",stdin);
//	freopen("CF568E.out","w",stdout);
	memset(low,0x7f7f7f7f,sizeof low);
	low[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),cnt[i]=cnt[i-1]+(a[i]==-1);
	a[++n]=0x7f7f7f7f; 
	cnt[n]=cnt[n-1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",s+i),set.insert(s[i]);
	std::sort(s+1,s+m+1);
	m=std::unique(s+1,s+m+1)-s-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			int l=1,r=n,mid,ans=0;
			while(l<=r){
				mid=(l+r)>>1;
				if(low[mid]<a[i])ans=mid,l=mid+1;
				else r=mid-1;
			}
			low[ans+1]=a[i],end[ans+1]=i;
			f[i]=ans+1,prev[i]=end[ans];
		}
		else{
			f[i]=-1;
			prev[i]=-1;
			for(int j=m,k=n;j;j--){
				while(low[k]>=s[j])--k;
				low[k+1]=s[j],end[k+1]=-1;
			}
		}
	}
	for(int i=n;i;){
		if(prev[i]==-1){
			for(int j=i-1;~j;--j){
				int tem;
				if(a[j]!=-1&&a[j]<a[i]&&f[i]-f[j]-1==std::min(cnt[i]-cnt[j],tem=find(a[i]-1)-find(a[j]))){
					for(int k=j+1,last=a[j];k<i&&cnt[k]-cnt[j]<=tem;k++)
						if(a[k]==-1){
							set.erase(set.find(a[k]=*set.upper_bound(last)));
							last=a[k];
						}
					i=j;
					break;
				}
			}
		}
		else i=prev[i];
	}
//	printf("%d\n",n-1);
	for(int i=1;i<n;i++){
		if(a[i]==-1)printf("%d ",*set.begin()),set.erase(set.begin());
		else printf("%d ",a[i]);
	}
}