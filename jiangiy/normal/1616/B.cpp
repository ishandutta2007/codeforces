#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005;
char s[N];
int n;
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d%s",&n,s);
		if(n>1&&s[1]<s[0]){
			int t=0;
			while(t+1<n&&s[t+1]<=s[t])t++;
			for(int i=0;i<=t;i++)putchar(s[i]);
			for(int i=t;i>=0;i--)putchar(s[i]);
			puts("");
		}
		else{
			printf("%c%c\n",s[0],s[0]);
		}
	}
}