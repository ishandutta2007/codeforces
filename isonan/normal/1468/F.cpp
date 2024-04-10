#include <cstdio>
#include <map>

std::map<std::pair<int,int> ,int>map;
int t,n,x[100001],y[100001],u[100001],v[100001];
int a,b,c,d;
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int abs(int x){
	return (x<0)?-x:x;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		map.clear();
		long long ans=0;
		a=b=c=d=0;
		for(int i=1;i<=n;i++){
			int x,y,u,v;
			scanf("%d%d%d%d",&x,&y,&u,&v);
			int dx=x-u,dy=y-v;
			int __gcd=gcd(abs(dx),abs(dy));
			dx/=__gcd,dy/=__gcd;
//			printf("%d %d\n",dx,dy);
			if(dx==0){
				if(dy>0)++a,ans+=b;
				else ++b,ans+=a;
			}
			else if(dy==0){
				if(dx>0)++c,ans+=d;
				else ++d,ans+=c;
			}
			else{
				++map[std::make_pair(dx,dy)];
				ans+=map[std::make_pair(-dx,-dy)];
			}
		}
		printf("%lld\n",ans);
	}
}