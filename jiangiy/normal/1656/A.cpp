#include<bits/stdc++.h>
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,mx=0,mn=2e9,px,pn;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x>mx)mx=x,px=i;
			if(x<mn)mn=x,pn=i;
		}
		printf("%d %d\n",px,pn);
	}
}