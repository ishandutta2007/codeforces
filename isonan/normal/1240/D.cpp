#include <cstdio>
#include <cstdlib>
#include <map> 

int q;
int n,a[300001],top,stk[300001],cnt;
const int P=998245313,P2=1000000009;
typedef std::pair<long long,long long> hash;
hash arr[300001];
hash add(hash x,int n){
	x.first=(1ll*x.first*56601+1ll*n*4553)%P;
	x.second=(1ll*x.second*47267+1ll*n*1023)%P2;
	return x;
}
std::map<hash,int>map;
int main(){
	scanf("%d",&q);
	for(int fd=1;fd<=q;fd++){
		scanf("%d",&n);
		arr[0]=std::make_pair(0ll,0ll);
		top=0;
		map.clear();
		++map[arr[0]];
		long long ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			if(stk[top]==a[i])--top;
			else{
				++top;
				stk[top]=a[i];
				arr[top]=add(arr[top-1],a[i]);
			}
			ans+=map[arr[top]];
			++map[arr[top]];
		}
		printf("%I64d\n",ans);
	}
}