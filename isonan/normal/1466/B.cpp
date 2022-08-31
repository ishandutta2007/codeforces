#include <cstdio>
#include <algorithm>

int t,x[100001],n;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		int ans=0;
		for(int i=1,last=0;i<=n;i++){
			scanf("%d",x+i);
			if(last==x[i]){
				++last;
				++ans;
			}
			else if(last<x[i]){
				last=x[i];
				++ans;
			}
		}
		printf("%d\n",ans);
	}
}