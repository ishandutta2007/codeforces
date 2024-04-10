#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
namespace io{
	const int Sz=1<<13;
	char ibuf[Sz],*ed=ibuf+Sz,*ips=ed-1;
	int getchar(){
		if(++ips==ed)ed=ibuf+fread(ips=ibuf,1,Sz,stdin);
		if(ips<ed)return*ips;else return EOF;
	}
}
#define getchar io::getchar
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f^=1;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return f?x:-x;
}
int main(){
	int n=read(),t=read();
	int ans=0x3f3f3f3f,ansn;
	for(int i=0;i<n;++i){
		int s=read(),d=read();
		int cur=s<=t?s+(t-s+d-1)/d*d:s;
		if(cur<ans)ans=cur,ansn=i;
	}
	printf("%d\n",ansn+1);
	return 0;
}