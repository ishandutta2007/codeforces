#include <cstdio>
#include <algorithm>

int n,t,d[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%1d",d+i);
		bool ansed=0;
		for(int j=0;j<9;j++){
			int mx=0,l=n,r=0,t1=0,t2=0;
			bool cando=1;
			for(int k=1;k<=n;k++)
				if(d[k]<j){
					t1=k;
					if(mx>d[k])cando=0;
					mx=std::max(mx,d[k]);
				}
			mx=0;
			for(int k=1;k<=n;k++)
				if(d[k]>j){
					if(!t2)t2=k;
					if(mx>d[k])cando=0;
					mx=std::max(mx,d[k]);
				}
			for(int k=1;k<=n;k++){
				if(d[k]==j){
					l=std::min(l,k),r=std::max(r,k);
					if(k<=t1&&k>=t2)cando=0;
				}
			}
			if(cando){
				ansed=1;
				for(int k=1;k<=n;k++)
					if(d[k]<j)putchar('1');
					else if(d[k]>j)putchar('2');
					else if(k>t1)putchar('1');
					else if(k<t2)putchar('2');
				putchar('\n');
				break;
			}
		}
		if(!ansed)puts("-");
	}
}