#include<iostream>
#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std; 
const int maxn=110;
int n;
int a[maxn];
bitset <maxn*2000> b;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
bool Check(){
	int cnt=0;
	for(register int i=1;i<=n;++i)
		cnt+=a[i];
	if(cnt&1)return true;
	b.reset();
	b[0]=1;
	for(register int i=1;i<=n;++i)
		b|=(b<<a[i]);
	return !b[cnt>>1];
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	if(Check())
		cout<<0<<endl;
	else{
		for(register int i=1,x;i<=n;++i){
			x=a[i];
			a[i]=0;
			if(Check()){
				cout<<1<<endl<<i<<endl;
				break;
			}
			a[i]=x;
		}
	}
	return 0;
}