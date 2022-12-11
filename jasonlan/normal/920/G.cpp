#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int Maxr=2e8;
int x,p,k,tnt;
vector <int> vp;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void divide(int px){
	vp.clear();
	for(register int i=2;i*i<=px;++i)
		if(px%i==0){
			vp.push_back(i);
			while(px%i==0)px/=i;
		}
	if(px^1)vp.push_back(px);
}
void dfs(int px,bool fg,int dep){
	if(dep==vp.size()){
		fg?tnt+=px:tnt-=px;
		return;
	}
	dfs(px/vp[dep],fg^1,dep+1);
	dfs(px,fg,dep+1);
}
int count(int px){
	tnt=0;
	dfs(px,1,0);
	return tnt;
}
int main(){
	for(register int T=read();T;--T){
		x=read();p=read();k=read();
		divide(p);
		int l=x+1,r=Maxr,mid;
		int xlc=count(x);
		while(l<r){
			mid=(l+r)>>1;
			if(count(mid)-xlc>=k)r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}