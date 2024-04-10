#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <map>

std::map<std::vector<int>,bool>map[201];
int n,b,stk[201],top,ans[201],Ans,tem[201],ta;
long long a[201];
char str[201];
bool vis[201];
bool get(){
	scanf("%s",str+1);
	return (str[1]=='y');
}
int cnt;
bool check1(int a,int top){
#ifdef ISONAN
	++cnt;
	long long x=0;
	for(int i=1;i<=top;i++)if(tem[i])x|=(1ll<<(1ll*b-i));
	return ::a[a]>(x+(1ll<<(1ll*b-top))-1);
#else 
	std::vector<int>now;
	for(int i=1;i<=top;i++)now.push_back(tem[i]);
	for(int i=top+1;i<=b;i++)now.push_back(1);
	if(map[a].count(now))return map[a][now];
	printf("%d ",a);
	for(int i=1;i<=top;i++)printf("%d",tem[i]);
	for(int i=top+1;i<=b;i++)putchar('1');putchar('\n');
	fflush(stdout);
	return map[a][now]=get();
#endif
}
bool check2(int a,int top){
#ifdef ISONAN
	++cnt;
	long long x=0;
	for(int i=1;i<=top;i++)if(tem[i])x|=(1ll<<(1ll*b-i));
	return ::a[a]>=x;
#else
	bool v=0;
	for(int i=1;i<=top;i++)v|=tem[i];
	if(!v)return 1;
	for(int i=top;i;i--){
		if(tem[i]){
			printf("%d ",a);
			for(int j=1;j<i;j++)printf("%d",tem[j]);
			putchar('0');
			for(int j=i+1;j<=b;j++)putchar('1');putchar('\n');
			fflush(stdout);
			return get();
		}
	}
#endif
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&b);
#ifdef ISONAN
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
#endif
	for(;ta<b;){
		top=0;
		int last=ta;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				bool bb=0;
				while(top){
					if(check1(i,ta)){
						bb=1;
						--ta;
						vis[stk[top]]=1;
						--top;
					}
					else break;
				}
				if(ta<b){
					stk[++top]=i;
					tem[++ta]=0;
					if(bb)tem[ta]=1;
					else 
					tem[ta]=check1(i,ta);
				}else vis[i]=1;
			}
		for(int j=top-1;j;--j){
			if(check1(stk[j],ta)){
				for(int k=j+1;k<=top;++k)vis[stk[k]]=1;
				ta=last+j;
				top=j;
			}
		}
//		cnt=L;
//		for(int i=1;i<=ta;i++)printf("(%d %d)",tem[i],1<<(b-i));putchar('\n');
	}
#ifdef ISONAN
	long long x=0;
	for(int i=1;i<=b;i++)if(tem[i])x|=(1ll<<(1ll*b-i));
	long long mx=0;
	for(int i=1;i<=n;i++)mx=std::max(mx,a[i]);
//	printf("%lld %lld\n",x,mx);
	printf("%d\n",cnt);
	assert(x==mx);
#else
	printf("0 ");
	for(int i=1;i<=b;i++)printf("%d",tem[i]);
	fflush(stdout);
#endif
}