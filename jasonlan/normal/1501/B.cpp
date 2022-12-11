#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=201000;
int n;
int a[maxn],b[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void process(){
	n=read();
	for(int i=0;i<=n;++i)
		b[i]=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[max(i-a[i]+1,1)]++;
		b[i+1]--;
	}
	for(int i=1;i<=n;++i){
		b[i]+=b[i-1];
		if(b[i]>0)cout<<"1 ";
		else cout<<"0 ";
	}
	cout<<endl;
}
int main(){
	int T=read();
	while(T--)process();
    return 0;
}