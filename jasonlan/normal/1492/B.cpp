#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=101000;
int n;
int a[maxn],ord[maxn];
bool cmp(int x,int y){
	return a[x]>a[y];
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			ord[i]=i;
		}
		sort(ord+1,ord+1+n,cmp);
		for(int i=1,back=n+1;i<=n;++i){
			if(back>ord[i]){
				for(int j=ord[i];j<back;++j)
					cout<<a[j]<<' ';
				back=ord[i];
			}
		}
		cout<<endl;
	}
	return 0;
}