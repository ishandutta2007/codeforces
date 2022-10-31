#include<bits/stdc++.h>
using namespace std;

int i,j,n,t,s[30],m;
char sb[1050];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%d\n",&n);
		for(i=1;i<=n;i++){
			gets(sb+1);
			m=strlen(sb+1);
			for(j=1;j<=m;j++){
				s[sb[j]-'a'+1]++;
			}
		}
		for(i=1;i<=26;i++){
			//printf("%d %d\n",i,s[i]);
			if(s[i]%n){puts("NO");goto aaa;}
		}
		puts("YES");
		aaa:;
	}
}