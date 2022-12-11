#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=101000;
int n,tie,cnt,zcnt;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	int T=read();
	while(T--){
		n=read();tie=0;
		for(int i=0;i<n;++i)
			a[i]=read(),tie^=a[i];
		if(!tie)puts("DRAW");
		else{
			while((tie&-tie)^tie)tie-=tie&-tie;
			cnt=zcnt=0;
			for(int i=0;i<n;++i)
				if(tie&a[i])++cnt;
				else ++zcnt;
			if(cnt%4==3&&zcnt%2==0)puts("LOSE");
			else puts("WIN");
		}
	}
	return 0;
}