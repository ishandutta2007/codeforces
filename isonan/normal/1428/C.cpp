#include <cstdio>
#include <cstring>

int t;
char str[200010];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%s",str+1);
		int n=strlen(str+1);
		int cnt=0,ans=0;
		for(int i=1,z=0;str[i];i++)
			if(str[i]=='A'){
				++cnt;
			}
			else{
				if(cnt){
					--cnt;
					++ans;
				}
				else{
					++z;
					if(z==2)z=0,++ans;
				}
			}
		printf("%d\n",n-2*ans);
	}
}