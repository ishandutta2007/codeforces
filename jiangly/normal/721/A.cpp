#include<bits/stdc++.h>
const int N=1e2+5;
int n,ans;
char s[N];
int l[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='B'){
			++ans;
			while(s[i]=='B'){
				++l[ans];
				++i;
			}
			--i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d ",l[i]);
	}
	return 0;
}