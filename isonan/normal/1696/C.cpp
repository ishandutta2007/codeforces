#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long

long long n,T,z,a[100001],m,b[100001],la,lb,tem[100001],k;
std::vector<std::pair<int,long long> >va,vb;
signed main(){
	scanf("%lld",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%lld%lld",&n,&m);
		va.clear(),vb.clear();
		for(int i=1,tem;i<=n;++i){
			scanf("%lld",&tem);
			long long cnt=1;
			while(tem%m==0)cnt*=m,tem/=m;
			if(!va.empty()&&tem==va.back().first){
				va.back().second+=cnt;
			}
			else va.push_back(std::make_pair(tem,cnt));
		}
		scanf("%lld",&k);
		for(int i=1,tem;i<=k;++i){
			scanf("%lld",&tem);
			long long cnt=1;
			while(tem%m==0)cnt*=m,tem/=m;
			if(!vb.empty()&&tem==vb.back().first){
				vb.back().second+=cnt;
			}
			else vb.push_back(std::make_pair(tem,cnt));
		}
		bool bb=0;
		if(va.size()!=vb.size())bb=1;
		else{
			for(int i=0;i<va.size();++i)
				if(va[i]!=vb[i])bb=1;
		}
		// for(auto v:va)printf("%d %d\n",v.first,v.second);
		// for(auto v:vb)printf("%d %d\n",v.first,v.second);
		if(bb)puts("No");
		else puts("Yes");
	}
}