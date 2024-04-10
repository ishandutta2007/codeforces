#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=1e5+10;
struct P{
	int sum,id;
}a[N];
bool cmp(P A,P B){
	if(A.sum!=B.sum) return A.sum>B.sum;
	return A.id<B.id;
}
int n;
int main(){
	scanf("%d",&n);
	int x,y,z,w;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d",&x,&y,&z,&w);
		a[i].sum+=x+y+z+w;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		if(a[i].id==1){
			printf("%d\n",i);return 0;
		}
	}
}