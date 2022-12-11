#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
string s;
int Asum,flag;
priority_queue <int> d;
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
		Asum=flag=0;
		cin>>s;
		s=s+'0';
		for(register int i=0,cnt=0;i<s.length();++i)
			if(s[i]=='1')++cnt;
			else if(cnt)
				d.push(cnt),cnt=0;
		while(d.size()){
			if(!flag)Asum+=d.top();
			flag^=1;
			d.pop();
		}
		printf("%d\n",Asum);
	}
	return 0;
}