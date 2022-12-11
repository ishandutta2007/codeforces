#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=201010,INF=0x3f3f3f3f;
int n;
char s[maxn];
int f[maxn];
int check(int p,string t){
	int res=0;
	for(int i=0;i<t.length();++i)
		if(s[p+i]!=t[i])++res;
	return res;
}
void proc(){
	scanf("%d%s",&n,s+1);
	int ans=INF;
	f[0]=0;f[1]=INF;
	for(int l=1;l<=4;++l){
		for(int i=1;i<=n;++i){
			f[i]=INF;
			if(i>=2)
				f[i]=min(f[i],f[i-2]+check(l+i-2,"RL"));
			if(i>=3){
				f[i]=min(f[i],f[i-3]+check(l+i-3,"RRL"));
				f[i]=min(f[i],f[i-3]+check(l+i-3,"RLL"));
			}
			if(i>=4)
				f[i]=min(f[i],f[i-4]+check(l+i-4,"RRLL"));
		}
		ans=min(ans,f[n]);
		s[n+l]=s[l];
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)proc();
	return 0; 
}