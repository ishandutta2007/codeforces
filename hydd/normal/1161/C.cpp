#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,mp[110];
int main(){
	scanf("%d",&n); int y=0x3f3f3f3f;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		mp[x]++; y=min(x,y);
	}
	if (mp[y]>n/2) puts("Bob");
	else puts("Alice");
	return 0;
}