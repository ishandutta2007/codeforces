#include <cstdio>

int cnt[26],t,n,k;
char str[201];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&k);
		scanf("%s",str+1);
		for(int i=0;i<26;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)++cnt[str[i]-'a'];
		for(int i=1;i<=k;++i){
			// bool bb=0;
			for(int j=0;j<='z'-'a'&&j+1<=n/k;++j){
				if(!cnt[j]){
					putchar(j+'a');
					// bb=1;
					break;
				}
				--cnt[j];
				if(j+1==n/k)putchar(j+1+'a');
			}
		}
		putchar('\n');
	}
}