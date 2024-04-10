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
const int N=3e5+5;
int n;
char s[N];
inline void no(){
	puts(":(");exit(0);
}
int main(){
	n=read();
	for(int i=0;i<n;++i)s[i]=getchar();
	if(s[0]!='?'&&s[0]!='(')no();s[0]='(';
	if(s[n-1]!='?'&&s[n-1]!=')')no();s[n-1]=')';
	vector<int>q;
	for(int i=1;i<n-1;++i)if(s[i]=='?'){
		q.PB(i);s[i]=')';
	}
	int cnt=0;
	for(int i=1,j=0;i<n-1;++i){
		if(s[i]=='(')++cnt;
		else{
			--cnt;
			if(cnt<0){
				if(j==(int)q.size()||q[j]>i)no();
				s[q[j]]='(';
				++j;cnt+=2;
			}
		}
	}
	if(!cnt)puts(s);
	else no();
	return 0;
}