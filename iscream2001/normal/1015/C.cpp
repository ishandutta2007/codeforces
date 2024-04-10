#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define LL long long
using namespace std;
const int N=1e6;
int n;
LL a[N],b[N],s,m;
int main(){
	scanf("%d%I64d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%I64d%I64d",&a[i],&b[i]);
		a[i]=a[i]-b[i];s+=b[i];
	}
	if(s>m){
		printf("-1\n");return 0;
	}
	int ans=n;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		if(s+a[i]<=m){
			--ans;
			s+=a[i];
		}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
/*
*/