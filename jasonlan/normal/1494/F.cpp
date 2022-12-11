#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int maxn=3010;
int n,m;
set<int> e[maxn],e2[maxn],ccel,elin;
set<int>::iterator it;
int eu[maxn],tnt;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void euler(int x){
	while(e2[x].size()){
		int y=*e2[x].begin();
		e2[x].erase(y);
		e2[y].erase(x);
		euler(y);
	}
	eu[++tnt]=x;
}
bool check(int x){
	if(!e[x].size())return false;
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(e[i].size()&1)++cnt;
	if(cnt==0||(cnt==2&&e[x].size()&1));
	else return false;
	for(int i=1;i<=n;++i)e2[i]=e[i];
	tnt=0;
	euler(x);
	return tnt-1+ccel.size()==m;
}
void output(int x){
	if(ccel.size())printf("%d\n",tnt+1+ccel.size()*2);
	else printf("%d\n",tnt);
	for(int i=1;i<=tnt;++i)
		printf("%d ",eu[i]);
	if(ccel.size()){
		printf("-1");
		while(ccel.size()){
			int y=*ccel.begin();
			printf(" %d %d",y,x);
			ccel.erase(y);
		}
	}
}
int main(){
	n=read();m=read();
	for(int i=1,x,y;i<=m;++i){
		x=read();y=read();
		e[x].insert(y);
		e[y].insert(x);
	}
	for(int i=1;i<=n;++i){
		elin=e[i];
		for(it=elin.begin();it!=elin.end();++it){
			if(e[*it].size()&1){
				ccel.insert(*it);
				e[*it].erase(i);
				e[i].erase(*it);
			}
		}
		if(check(i)){
			output(i);return 0;
		}
		for(it=elin.begin();it!=elin.end();++it){
			int x=*it;
			if(e[i].count(x)){
				ccel.insert(x);
				e[x].erase(i);
				e[i].erase(x);
			}
			else{
				ccel.erase(x);
				e[x].insert(i);
				e[i].insert(x);
			}
			if(check(i)){
				output(i);return 0;
			}
			if(e[i].count(x)){
				ccel.insert(x);
				e[x].erase(i);
				e[i].erase(x);
			}
			else{
				ccel.erase(x);
				e[x].insert(i);
				e[i].insert(x);
			}
		}
		for(it=elin.begin();it!=elin.end();++it){
			int x=*it;
			if(!e[i].count(x)){
				ccel.erase(x);
				e[x].insert(i);
				e[i].insert(x);
			}
		}
	}
	puts("0");
	return 0;
}