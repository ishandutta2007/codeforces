#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int>vec[300001];
int a[300001],n,b[300010],c[300010],P=1000000007,inv[300010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		for(int j=2;j*j<=a[i];++j)
			if(a[i]%j==0){
				int tem=0;
				while(a[i]%j==0)a[i]/=j,++tem;
				vec[j].push_back(tem);
			}
		if(a[i]>1)vec[a[i]].push_back(1);
	}
	for(int i=1;i<=300000;i++)
		if(vec[i].size()){
			int start=n-vec[i].size()+1;
			std::sort(vec[i].begin(),vec[i].end());
			for(std::vector<int>::iterator it=vec[i].begin();it!=vec[i].end();++it)
				b[start++]+=*it;
		}
	inv[1]=1;
	for(int i=2;i<=n+1;i++)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	for(int i=0,com=1;i<n;++i){
		c[i]=com;
		if(i)(c[i]+=c[i-1])%=P;
		com=1ll*com*(n-i-1)%P*inv[i+1]%P;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		(ans+=1ll*(c[i-1]+P-c[n-i])*b[i]%P)%=P;
	}
	printf("%d",ans);
}