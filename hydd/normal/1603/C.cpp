#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
int T,n,a[210000];
pii b[210000],c[210000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		ll ans=0,res=0; int cnt=0;
		for (int i=n;i>=1;i--){
			for (int j=1;j<=cnt;j++){
				int tmp=(a[i]+b[j].first-1)/b[j].first;
				res=(res+1ll*(tmp-1)*b[j].second)%Mod; b[j].first=a[i]/tmp;
			}
			bool flag=false;
			int cnt2=0;
			for (int j=1;j<=cnt;j++){
				if (!flag&&b[j].first>a[i]){
					if (cnt2&&a[i]==c[cnt2].first) c[cnt2].second++;
					else c[++cnt2]=pii(a[i],1);
					flag=true;
				}
				if (b[j].first==c[cnt2].first) c[cnt2].second+=b[j].second;
				else c[++cnt2]=b[j];
			}
			if (!flag){
				if (cnt2&&a[i]==c[cnt2].first) c[cnt2].second++;
				else c[++cnt2]=pii(a[i],1);
				flag=true;
			}
			cnt=cnt2;
			for (int j=1;j<=cnt;j++) b[j]=c[j];
			ans=(ans+res)%Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}