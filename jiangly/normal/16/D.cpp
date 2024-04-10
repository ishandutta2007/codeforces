#include<bits/stdc++.h>
int n,ans;// https://www.luogu.org/
std::string s;
int main(){
	scanf("%d ",&n);
	int last=1440,cnt=0;
	for(int i=1;i<=n;++i){
		std::getline(std::cin,s);
		int x=((s[1]-'0')*10+(s[2]-'0'))%12*60+(s[4]-'0')*10+s[5]-'0'+(s[7]=='p')*720;
		cnt=x==last?cnt+1:1;
		if(cnt>10){
			cnt=1;
			last=1440;
		}
		ans+=x<last;
		last=x;
	}
	printf("%d\n",ans);
	return 0;
}