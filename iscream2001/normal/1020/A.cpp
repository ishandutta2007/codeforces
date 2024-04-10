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
int n,h,a,b,k;
int main(){
	int A,B,C,D,ans;
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	while(k--){
		ans=0;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		if(A==C){
			ans=abs(B-D);
			printf("%d\n",ans);
		}
		else{
			if(B<a) ans+=a-B,B=a;
			else if(B>b) ans+=B-b,B=b;
			ans+=abs(A-C)+abs(B-D);
			printf("%d\n",ans);
		}
	}
	return 0;
}