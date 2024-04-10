#include <cstdio>
#include <cstring>

char str[1000001],str1[1000001];
int main(){
	scanf("%s",str+1);
	scanf("%s",str1+1);
	int n1=strlen(str+1),n2=strlen(str1+1);
	bool cnt=0,cnt1=0;
	for(int i=1;i<=n2;i++)if(str1[i]=='1')cnt1^=1;
	for(int i=1;i<=n2;i++)if(str[i]=='1')cnt^=1;
	int ans=0;
	for(int i=n2;i<=n1;i++){
		if(cnt==cnt1)++ans;
		if(str[i+1]=='1')cnt^=1;
		if(str[i-n2+1]=='1')cnt^=1;
	}
	printf("%d\n",ans);
}