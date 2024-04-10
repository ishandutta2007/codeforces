#include<bits/stdc++.h>
using namespace std;
const int M=200009;
int n;
char s[M];
void work(){
	long long ans=0;
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1,la=0,l=0;i<=n;++i){
		if(s[i]!='?'){
			if((s[i]==s[la])==((i-la)%2))l=la;
			la=i;
		}
		ans+=i-l;
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
*/