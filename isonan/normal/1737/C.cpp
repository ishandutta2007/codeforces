#include <cstdio>

int t,p[3][2];
int main(){
	scanf("%d",&t);
	int n;
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=0;i<3;++i)scanf("%d%d",&p[i][0],&p[i][1]);
		int x,y;
		scanf("%d%d",&x,&y);
		bool bb=0;
		for(int i=0;i<3;++i){
			if(x%2==p[i][0]%2&&y%2==p[i][1]%2){
				bb=1;
				break;
			}
		}
		if(!bb){
			puts("NO");
			continue;
		}
		int co;
		for(int i=0;i<3;++i){
			bool bb=1;
			for(int j=0;j<3;++j)
				if(j!=i){
					if(p[j][0]%2==p[i][0]%2||p[j][1]%2==p[i][1]%2);
					else bb=0;
				}
			if(bb)co=i;
		}
		if((p[co][0]==1&&p[co][1]==1)||(p[co][0]==n&&p[co][1]==1)||(p[co][0]==1&&p[co][1]==n)||(p[co][0]==n&&p[co][1]==n)){
			if(x==p[co][0]||y==p[co][1])puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
}