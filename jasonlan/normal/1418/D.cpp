#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,q,cnt;
multiset <int> s,ms;
multiset<int>::iterator it,nxt,pre;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int x){
	it=s.insert(x);
	if(*it!=*s.rbegin()){
		nxt=it;++nxt;
		ms.insert(*nxt-x);
	}
	if(*it!=*s.begin()){
		pre=it;--pre;
		ms.insert(x-*pre);
		if(*it!=*s.rbegin())ms.erase(ms.find(*nxt-*pre));
	}
	++cnt;
}
void erase(int x){
	it=s.find(x);
	if(*it!=*s.rbegin()){
		nxt=it;++nxt;
		ms.erase(ms.find(*nxt-x));
	}
	if(*it!=*s.begin()){
		pre=it;--pre;
		ms.erase(ms.find(x-*pre));
		if(*it!=*s.rbegin())ms.insert(*nxt-*pre);
	}
	s.erase(it);
	--cnt;
}
void query(){
	if(cnt<=2)puts("0");
	else printf("%d\n",*s.rbegin()-*s.begin()-*ms.rbegin());
}
int main(){
	n=read();q=read();
	for(register int i=1;i<=n;++i)add(read());
	query();
	for(register int i=1;i<=q;++i){
		read()?add(read()):erase(read());
		query();
	}
	return 0;
}