#include <cstdio>
#include <algorithm>
const int Maxn=100000;
char s[Maxn+5];
int n;
int num[26];
void solve(){
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	for(int i=0;i<26;i++){
		num[i]=0;
	}
	for(int i=1;i<=n;i++){
		num[s[i]-'a']++;
	}
	int minn=n+1;
	for(int i=0;i<26;i++){
		if(num[i]>0){
			minn=std::min(minn,num[i]);
		}
	}
	if(minn==n){
		puts(s+1);
		return;
	}
	if(minn==1){
		int pos=-1;
		for(int i=0;i<26;i++){
			if(num[i]==1){
				pos=i;
				break;
			}
		}
		putchar((char)(pos+'a'));
		num[pos]--;
		for(int i=0;i<26;i++){
			while(num[i]>0){
				putchar((char)(i+'a'));
				num[i]--;
			}
		}
		putchar('\n');
		return;
	}
	int pos=-1;
	for(int i=0;i<26;i++){
		if(num[i]>0){
			pos=i;
			break;
		}
	}
	if(num[pos]-2>n-num[pos]){
		int val=0;
		for(int i=0;i<26;i++){
			if(num[i]>0){
				val++;
			}
		}
		if(val>=3){
			int nxt_1,nxt_2;
			nxt_1=pos+1;
			while(num[nxt_1]==0){
				nxt_1++;
			}
			nxt_2=nxt_1+1;
			while(num[nxt_2]==0){
				nxt_2++;
			}
			putchar((char)(pos+'a'));
			num[pos]--;
			putchar((char)(nxt_1+'a'));
			num[nxt_1]--;
			while(num[pos]>0){
				putchar((char)(pos+'a'));
				num[pos]--;
			}
			putchar((char)(nxt_2+'a'));
			num[nxt_2]--;
			for(int i=0;i<26;i++){
				while(num[i]>0){
					putchar((char)(i+'a'));
					num[i]--;
				}
			}
			putchar('\n');
			return;
		}
		int nxt=pos+1;
		while(num[nxt]==0){
			nxt++;
		}
		putchar((char)(pos+'a'));
		num[pos]--;
		while(num[nxt]>0){
			putchar((char)(nxt+'a'));
			num[nxt]--;
		}
		for(int i=0;i<26;i++){
			while(num[i]>0){
				putchar((char)(i+'a'));
				num[i]--;
			}
		}
		putchar('\n');
	}
	else{
		putchar((char)(pos+'a')),putchar((char)(pos+'a'));
		num[pos]-=2;
		for(int i=pos+1;i<26&&num[pos]>0;i++){
			while(num[i]>0&&num[pos]>0){
				putchar((char)(i+'a')),putchar((char)(pos+'a'));
				num[i]--,num[pos]--;
			}
		}
		for(int i=0;i<26;i++){
			while(num[i]>0){
				putchar((char)(i+'a'));
				num[i]--;
			}
		}
		putchar('\n');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}