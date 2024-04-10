#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=101000;
typedef long long ll;
int n,k;
int cnt[maxn],dep[maxn];
vector <int> v[maxn];
ll p;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void dfs(int p){
	++cnt[dep[p]];
	for(register int i=0;i<v[p].size();++i){
		if(dep[v[p][i]]||v[p][i]==1)continue;
		dep[v[p][i]]=dep[p]+1;
		dfs(v[p][i]);
	}
}
bool check(int v){
	int lp=0,tnt=0,lptnt=0;
	ll money=0;
	for(register int i=1;cnt[i];++i){
		money+=tnt;
		tnt+=cnt[i];
		if(tnt<v)continue;
		while(tnt>v){
			if(tnt-v<lptnt){
				money-=1ll*(tnt-v)*(i-lp);
				lptnt-=tnt-v;
				tnt=v;
				break;
			}
			money-=1ll*lptnt*(i-lp);
			tnt-=lptnt;
			++lp;
			lptnt=cnt[lp];
		}
		if(money<=p)return true;
	}
	return false;
}
int main(){
	n=read();k=read();p=read();
	if(!k){
		puts("0");return 0;
	}
	for(register int i=1,x,y;i<n;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int l=1,r=min(n-1,k),mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(!check(mid))r=mid-1;
		else l=mid;
	}
	printf("%d",l);
    return 0;
}