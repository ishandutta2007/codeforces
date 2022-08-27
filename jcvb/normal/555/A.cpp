//dzy~

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=1e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int n,m,k,x,l[N];
int main(){
	scanf("%d%d", &n, &k);
	int ret=0;
	for(int i = 1;i <= k;i ++){
		scanf("%d", &m);
		int tmp=0;
		for(int j = 1;j <= m;j ++) scanf("%d", &l[j]);
		for(int j = 1;j <= m;j ++) if(l[j] == j) tmp+=2; else break;
		if(l[1]==1) ret=tmp;
	}
	printf("%d\n",2*n+1-ret-k);
	return 0;
}