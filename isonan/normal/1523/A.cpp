#include <cstdio>
#include <algorithm>

int t;
int n,m;
char str[1001];
void set(int l,int r){
	for(int i=l;i<=r;++i)str[i]='1';
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		scanf("%s",str+1);
		int last=0;
		for(int i=1,pre=0;i<=n;++i)
			if(str[i]=='1'){
				if(pre){
					int x=std::min(m,(i-pre-1)>>1);
					set(pre+1,pre+x);
					set(i-x,i-1);
				}
				else{
					set(i-(std::min(m,i-1)),i-1);
				}
				pre=last=i;
			}
		if(last)set(last+1,last+std::min(m,n-last));
		printf("%s\n",str+1);
	}
}