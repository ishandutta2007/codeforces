#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=201100;
int n,m;
int ans[maxn],cnt[maxn];
vector <int> v[maxn],e[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
void process(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		v[i].clear();cnt[i]=0;
	}
	for(int i=1;i<=m;++i)
		e[i].clear();
	bool flag=true;
	for(int i=1;i<=m;++i)
		for(int k=read(),x;k;--k)
			e[i].push_back(read());
	for(int i=1;i<=m;++i){
		int to=e[i][0];
		if(cnt[to]<(m+1)/2){
			ans[i]=to;
			++cnt[to];
			if(e[i].size()>1)
				v[to].push_back(i);
		}
		else{
			if(e[i].size()>1)
				ans[i]=e[i][1];
			else{
				if(!v[to].size()){
					puts("NO");return;
				}
				ans[i]=to;
				int pto=v[to].back();
				ans[pto]=e[pto][1];
				v[to].pop_back();
			}
		}
	}
	puts("YES");
	for(int i=1;i<=m;++i)
		printf("%d ",ans[i]);
	cout<<endl;
}
int main(){
	int T=read();
	while(T--)process();
	return 0;
}