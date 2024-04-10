#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

int con[200001],c[200001];
long long ans,n;
void update(int ind){for(;ind<=n<<1;ind+=ind&-ind)++c[ind];}
int query(int ind){int tot=0;for(;ind;ind-=ind&-ind)tot+=c[ind];return tot;}
int main(){
	scanf("%I64d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		con[x]=y;
		con[y]=x;
	}
	long long tem1=0,tem2=0;
	for(int i=1;i<=n<<1;i++)
		if(con[i]<i){
			long long x=query(i)-query(con[i]-1),y=i-con[i]-1-(x<<1);
			tem1+=y*(n-1ll-y);
			tem2+=x*(n-1ll-x-y);
			update(con[i]);
		}
	printf("%I64d\n",(n*(n-1)*(n-2))/6-(tem1>>1)-tem2);
}