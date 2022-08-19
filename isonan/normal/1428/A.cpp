#include <cstdio>
#include <algorithm>

int t;
int x1,y1,x2,y2;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)printf("%d\n",std::abs(y1-y2));
		else if(y1==y2)printf("%d\n",std::abs(x1-x2));
		else printf("%d\n",std::abs(x1-x2)+std::abs(y1-y2)+2);
	}
}