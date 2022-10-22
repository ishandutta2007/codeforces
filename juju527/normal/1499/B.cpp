#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
char s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		scanf("%s",s+1);n=strlen(s+1);
		int pos0=0,pos1=n+1;
		for(int i=1;i<n;i++)if(s[i]=='1'&&s[i+1]=='1'){pos1=i;break;}
		for(int i=n;i>1;i--)if(s[i]=='0'&&s[i-1]=='0'){pos0=i-1;break;}
		if(pos0<=pos1)puts("YES");
		else puts("NO");
	}
    return 0;
}