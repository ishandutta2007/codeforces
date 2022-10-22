#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int N=1e5+50;
int n,ans=0;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n,j=n;j>=1;){
		if(a[i]>a[j]){
			++ans;--i;--j;
		}
		else --j;
	}
	printf("%d\n",ans);
	return 0;
}