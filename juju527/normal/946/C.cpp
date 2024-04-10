#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	bool tag=0;
	int cur='a';
	for(int i=1;i<=n;i++){
		if(s[i]<=cur){
			s[i]=cur;
			cur++;
			if(cur>'z')break;
		}
	}
	if(cur>'z')cout<<s+1<<endl;
	else puts("-1");
	return 0;
}