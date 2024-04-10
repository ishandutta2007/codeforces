#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100010,maxe=301100;
int n;
priority_queue <int> q;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	int T=read();
	while(T--){
		n=read();
		while(q.size())q.pop();
		for(register int i=0;i<n;++i)
			q.push(read());
		for(register int i=0,pre=0,val;;i^=1){
			if(q.empty()){
				puts(i?"T":"HL");break;
			}
			val=q.top()-1;
			q.pop();
			if(pre)q.push(pre);
			pre=val;
		}
	}
	return 0;
}