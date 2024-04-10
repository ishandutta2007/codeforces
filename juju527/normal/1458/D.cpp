//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,D=5e5;
char s[maxn];
int e[2*maxn][2];
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
		scanf("%s",s+1);
		int n=strlen(s+1);
		int aux=0;
		for(int i=1;i<=n;i++){
			e[aux+D][s[i]-'0']++;
			if(s[i]=='0')aux--;else aux++;
		}
		aux=0;
		for(int i=1;i<=n;i++){
			if(e[aux+D][0]&&e[aux-1+D][1])e[aux+D][0]--,aux--,putchar('0');
			else if(e[aux+D][1])e[aux+D][1]--,aux++,putchar('1');
			else e[aux+D][0]--,aux--,putchar('0');
		}
		puts("");
	}
    return 0;
}