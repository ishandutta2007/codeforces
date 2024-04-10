#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=510;
int n,m;
char s[maxn][maxn];
bool isexist[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool check(int p){
	for(int i=1;i<=m;++i)
		if(s[p][i]=='X')return false;
	return true;
}
void process(){
	n=read();m=read();
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i+=3){
		for(int j=1;j<=m;++j)
			s[i][j]='X';
		if(i+1==n)break;
		else if(i+2==n){
			for(int j=1;j<=m;++j)
				if(s[i+2][j]=='X')
					s[i+1][j]='X';
			break;
		}
		else{
			if(check(i+1)){
				if(check(i+2)){
					s[i+1][1]=s[i+2][1]='X';
				}
				else{
					for(int j=1;j<=m;++j)
						if(s[i+2][j]=='X'){
							s[i+1][j]='X';break;
						}
				}
			}
			else{
				for(int j=1;j<=m;++j)
					if(s[i+1][j]=='X'){
						s[i+2][j]='X';break;
					}
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%s\n",s[i]+1);
	return;
}
int main(){
	int T=read();
	while(T--)process();
	return 0;
}