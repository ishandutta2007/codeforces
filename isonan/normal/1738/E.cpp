#include <cstdio>
#include <map>
#include <vector>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int t,n,a[100010];
long long S1[100010],S2[100010];
int _mul[4000001],invmul[4000001];
std::map<long long,int>map;
std::vector<std::pair<int,int> >vec[200010];
int cnt;
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int main(){
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=4000000;++i)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=4000000;++i)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=4000000;++i)invmul[i]=mul(invmul[i-1],invmul[i]);
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=1;i<=n;++i){
			S1[i]=S1[i-1]+a[i];
		}
		S2[n+1]=0;
		for(int i=n;i;--i){
			S2[i]=a[i];
			if(i<n)S2[i]+=S2[i+1];
		}
		cnt=0;
		map.clear();
		for(int i=1;i<=n;++i){
			int &p=map[S1[i]];
			if(!p)vec[p=++cnt].clear();
			vec[p].push_back(std::make_pair(i,1));
		}
		for(int i=1;i<=n;++i){
			int &p=map[S2[i]];
			if(!p)vec[p=++cnt].clear();
			vec[p].push_back(std::make_pair(i,2));
		}
		int tot=1;
		for(int i=1;i<=cnt;++i){
			// for(auto v:vec[i])printf("(%d %d)",v.first,v.second);putchar('\n');
			int mx=0,mn=0x7f7f7f;
			for(auto v:vec[i])if(v.second==1)mx=std::max(mx,v.first);
			for(auto v:vec[i])if(v.second==2)mn=std::min(mn,v.first);
			if(mx+1<mn){
				int n=0,m=0;
				for(auto v:vec[i])if(v.second==1)++n;else++m;
				int sum=0;
				for(int i=0;i<=n;++i)sum=add(sum,mul(C(n,i),C(m,i)));
				tot=mul(tot,sum);
			}
		}
		int cnt=0;
		for(int i=1;i<n;++i)if(S1[i]==S2[i+1])++cnt;
		int sum=0;
		for(int i=0;i<=cnt;++i)sum=add(sum,C(cnt,i));
		tot=mul(tot,sum);
		printf("%d\n",tot);
	}
}