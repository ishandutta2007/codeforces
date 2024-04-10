#include <cstdio>
#include <cstring>

int t;
char str[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%s",str+1);
		int n=strlen(str+1);
		int ans=0x7f7f7f7f,tem=0;
		bool v[2]={0,0};
		for(int i=1;i<=n;++i){
			v[str[i]-'0']=1;
			if(i==1||str[i]!=str[i-1]){
				if(str[i]=='0')++tem;
			}
		}
		ans=tem;
		int cnt=(v[0]?(v[1]?2:1):0);
		if(ans>cnt)ans=cnt;
		printf("%d\n",ans);
	}
}