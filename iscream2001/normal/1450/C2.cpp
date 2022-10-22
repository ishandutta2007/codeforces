#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
char s[505][505];
int k,cnt,n;
inline bool check(int x,int y){
	if(x==y)	return 0;
	int cnt=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(s[i][j]=='X'&&(i+j)%3==x)cnt++;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(s[i][j]=='O'&&(i+j)%3==y)cnt++;	
	if(cnt<=k/3){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)if(s[i][j]=='X'&&(i+j)%3==x)	s[i][j]='O';
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)if(s[i][j]=='O'&&(i+j)%3==y)	s[i][j]='X';	
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) putchar(s[i][j]);
			puts("");
		}
		return 1;
	}
	return 0;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		k=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) if(s[i][j]!='.') ++k;
		bool flag=0;
		for(int mo=0;mo<=2&&flag==0;++mo){	
			for(int mo1=0;mo1<=2;++mo1)	if(check(mo,mo1))	
				{flag=1;break;}
		}
	}
}