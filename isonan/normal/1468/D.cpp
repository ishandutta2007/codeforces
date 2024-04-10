#include <cstdio>
#include <algorithm> 

int t,s[200010];
int n,m,a,b;
int abs(int x){
	return (x<0)?-x:x;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		int t1=abs(a-b)-1,t2=(a<b)?a-1:(n-a);
		for(int i=1;i<=m;i++)scanf("%d",s+i);
		std::sort(s+1,s+m+1);
		int now=m,ans=0;
		for(int i=1;i<=t1;i++){
			while(now&&s[now]>t2+t1-i+1)--now;
			if(now)++ans,--now;
			else break;
		}
		printf("%d\n",ans);
	}
}