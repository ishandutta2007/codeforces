#include<cstdio>
#include<cstring>
using namespace std;
int T;
char s[110];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int l=-1,r;
		for (int i=1;i<=n;i++)
			if (s[i]=='1'){
				l=i;
				break;
			}
		if (l==-1){
			puts("0");
			continue;
		}
		for (int i=n+1;i>=1;i--)
			if (s[i]=='1'){
				r=i;
				break;
			}
		int sum=0;
		for (int i=l;i<=r;i++) sum+=(s[i]-'0');
		printf("%d\n",r-l+1-sum);
	}
	return 0;
}