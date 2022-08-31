#include <cstdio>
#include <queue>

int T;
long long n,k,r,cnt,h,t,len,C,ans;
long long bel(long long x){return (x-1)/len;}
long long find(long long x){
	if(!x)return (k*(k+1))>>1ll;
	long long start=(x*len+1-C)/k,pos=bel(start),begin=pos*len+1,v=find(pos);
	begin+=((start-begin+k-1)/k)*k;
	if(begin>=v)++begin;
	long long bef=pos+(begin>v);
	ans=begin+(begin-1-bef)/k-bef;
//	printf("find %lld %lld %lld\n",x,begin,begin*k+C);
	return begin*k+C+(v>=begin&&v<begin+k)*(begin+k-v);
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%lld%lld",&n,&k);
		len=k*k+1;
		C=(k*(k-1))>>1ll;
		long long tem=find(bel(n));
		if(tem==n)printf("%lld\n",bel(n)?(ans+k):k+1);
		else printf("%lld\n",n+(n-1-(bel(n)+(tem<n)))/k-(bel(n)+(tem<n)));
	}
}