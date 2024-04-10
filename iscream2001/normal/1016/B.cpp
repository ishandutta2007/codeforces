#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
const int N=1e3+10;
int n,m,q;
char s[N],t[N];
int a[N];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",s+1,t);
	bool f=0;
	for(int i=1;i<=n-m+1;++i){
		f=0;
		for(int j=0;j<m;++j)
			if(s[i+j]!=t[j]){
				f=1;break;
			}
		if(f==0) ++a[i];
	}
	int l,r;
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	while(q--){
		scanf("%d%d",&l,&r);
		if(r-l+1<m) {
			printf("0\n");
			continue;
		}
		r=r-m+1;--l;
		printf("%d\n",a[r]-a[l]);
	}
	return 0;
}