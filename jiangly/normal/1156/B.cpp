#include<bits/stdc++.h>
const int MAXT=100,MAXN=100;
int T;
int n;
char s[MAXN+5];
int cnt[26];
int tot;
int tp[26];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		tot=0;
		for(int i=1;i<=n;++i){
			++cnt[s[i]-'a'];
		}
		for(int i=0;i<26;++i){
			if(cnt[i]){
				tp[tot++]=i;
			}
		}
		if(tot==1){
			puts(s+1);
		}else if(tot==2){
			if(tp[0]+1==tp[1]){
				puts("No answer");
			}else{
				puts(s+1);
			}
		}else if(tot==3){
			if(tp[0]+1==tp[1]&&tp[1]+1==tp[2]){
				puts("No answer");
			}else{
				if(tp[1]+1==tp[2]){
					std::swap(tp[0],tp[2]);
				}
				for(int i=1;i<=cnt[tp[0]];++i){
					putchar('a'+tp[0]);
				}
				for(int i=1;i<=cnt[tp[2]];++i){
					putchar('a'+tp[2]);
				}
				for(int i=1;i<=cnt[tp[1]];++i){
					putchar('a'+tp[1]);
				}
				puts("");
			}
		}else{
			for(int i=1;i<tot;i+=2){
				for(int j=1;j<=cnt[tp[i]];++j){
					putchar('a'+tp[i]);
				}
			}
			for(int i=0;i<tot;i+=2){
				for(int j=1;j<=cnt[tp[i]];++j){
					putchar('a'+tp[i]);
				}
			}
			puts("");
		}
	}
	return 0;
}