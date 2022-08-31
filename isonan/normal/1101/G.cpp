#include <cstdio>
#include <cstring>
#include <vector>

struct basis{
	int Base[32],count;
	basis(){memset(Base,0,sizeof Base);count=0;}
	void add(int x){
		for(int i=31;~i;--i)
			if(x&(1<<i)){
				if(!Base[i]){
					Base[i]=x;
					++count;
					return;
				}
				x^=Base[i];
			}
	}
	int getmx(){
		int ans=0;
		for(int i=20;~i;--i)
			if(ans<(ans^Base[i]))ans^=Base[i];
		return ans;
	}
	void print(){
		for(int i=20;~i;--i)printf("%d ",Base[i]);putchar('\n');
	}
}BASIS;
int n,a[1000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),BASIS.add(a[i]^=a[i-1]);
	printf("%d\n",a[n]?BASIS.count:-1);
}