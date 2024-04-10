#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k;
char s[1010];
int main(){
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%s",s+1),n=strlen(s+1);
		for(int i=1,now='2',tmp=0;i<=n;i++){
			if(tmp==0) now=s[i],tmp=1;
			else if(s[i]=='1'){
				if(now=='0'&&tmp) cnt++,tmp--;
				else tmp++;
			}
			else if(s[i]=='0'){
				if(now=='1'&&tmp) cnt++,tmp--;
				else tmp++;
			}
		}
		puts(cnt%2?"DA":"NET");
	}
}