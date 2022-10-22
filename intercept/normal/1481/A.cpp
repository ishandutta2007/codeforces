#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int px,py;
char s[M];
void work(){
	scanf("%d%d",&px,&py);
	scanf("%s",s+1);
	for(int len=strlen(s+1),i=1;i<=len;++i){
		if(px<0&&s[i]=='L')px++;
		if(px>0&&s[i]=='R')px--;
		if(py<0&&s[i]=='D')py++;
		if(py>0&&s[i]=='U')py--;
	}
	if(!px&&!py)printf("YES\n");
	else printf("NO\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}