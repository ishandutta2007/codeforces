#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int N=100005;
int n;
int p[N];
bool vis[1010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	int x;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) vis[j]=0;
		x=i;
		while(!vis[x]){
			vis[x]=1;x=p[x];
		}
		printf("%d",x);
		if(i!=n) printf(" ");
	}
	printf("\n");
	return 0;
}