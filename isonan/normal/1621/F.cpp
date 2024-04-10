#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,a,b,c;
char s[200001];
std::vector<int>vec;
long long solve(bool f){
	int cnt=0;
	for(int i=2;i<=n;++i)if(s[i]==s[i-1]&&s[i]=='1')++cnt;
	int c1=-1,c2=-1,res=0,rr=0;
	vec.clear();
	for(int i=1;i<=n;++i)
		if(s[i]=='0'){
			int j=i;
			while(j<n&&s[j+1]=='0')++j;
			if(i==1)c1=j-i;
			else if(j==n)c2=j-i;
			else{
				vec.push_back(j-i);
			}
			i=j;
		}
	std::sort(vec.begin(),vec.end());
	std::reverse(vec.begin(),vec.end());
	long long ans=0,tot=0;
	if(f){
		if(!cnt)return tot;
		--cnt,ans+=b;
	}
	for(;;){
		tot=std::max(ans,tot);
		while(!vec.empty()&&!vec.back()){
			++res;
			vec.pop_back();
		}
		if(!c1)c1=-1,++rr;
		if(!c2)c2=-1,++rr;
		if((!cnt)&&res){
			--res,++cnt,ans-=c;
		}
		else
			if(!vec.empty())--vec.back(),ans+=a;
			else if(c1>0||c2>0){
				if((c1>0&&c1<=c2)||c2<=0)--c1,ans+=a;
				else --c2,ans+=a;
			}
			else if(res)--res,++cnt,ans-=c;
			else if(rr)--rr,ans-=c;
			else return tot;
		tot=std::max(ans,tot);
		if(!cnt)return tot;
		--cnt,ans+=b;
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s+1);
		int B[2]={0,0};
		for(int i=2;i<=n;++i){
			if(s[i]==s[i-1])++B[s[i]=='1'];
		}
		int x=std::min(B[0],B[1]),y=x;
		if(B[0]>x)++x;
		else if(B[0]!=B[1])++y;
		long long ans=solve(0);
		ans=std::max(ans,solve(1));
		ans=std::max(ans,1ll*x*a+1ll*y*b);
		printf("%lld\n",ans);
	}
}