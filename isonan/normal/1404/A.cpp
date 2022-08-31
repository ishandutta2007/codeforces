#include <cstdio>

int n,t,k,cnt[300001];
char s[300001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=0;i<=n;i++)cnt[i]=-1;
		for(int i=1;i<=n;i++)
			if(s[i]!='?')cnt[i%k]=s[i];
		bool cando=1;
		for(int i=1;i<=n;i++){
			if(s[i]!='?'){
				if(s[i]!=cnt[i%k]){
					cando=0;
					break;
				}
			}else if(cnt[i%k]!=-1)s[i]=cnt[i%k];
		}
//		for(int i=1;i<=n;i++)putchar(s[i]);putchar('\n');
		int cnt1=0,cnt2=0;
		for(int i=1;i<=k;i++){
			cnt1+=(s[i]=='0');
			cnt2+=(s[i]=='1');
		}
//		printf("%d %d %d\n",cando,cnt1,cnt2);
		if(cando&&cnt1<=(k>>1)&&cnt2<=(k>>1)){
			puts("YES");
		}
		else puts("NO");
	}
}