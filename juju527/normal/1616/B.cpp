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
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		scanf("%s",s+1);
		bool tag=0;
		int pos=n;
		for(int i=2;i<=n;i++){
			if(s[i]!=s[1])tag=1;
			if(s[i]>s[i-1]){pos=i-1;break;}
			if(s[i]==s[i-1]&&!tag){pos=i-1;break;}
		}
		for(int i=1;i<=pos;i++)cout<<s[i];
		for(int i=pos;i>=1;i--)cout<<s[i];
		cout<<endl;
	}
    return 0;
}