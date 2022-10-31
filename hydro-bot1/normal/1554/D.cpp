// Hydro submission #6125d238f62c0b8969557142@1629868600623
// Problem: D. Diane
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

//writer:haze12261701
#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
#define N 500099
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char cur;
void nxt(){
	putchar(cur);
	++cur;
}
void add(int n){
	for(int i=1;i<=n;++i){
		putchar('a');
	}
}
int main(){
	int T=read();
	while(T	--){
		cur='b';
		int n=read(),fl=0;
		if(n<=26){
			for(char kk='a';n;n--){
				putchar(kk);
				++kk;
			}
			cout<<endl;
			continue;
		}
		if(n%2==0)fl=1,n++;
		//fl=1->a
		int s=(n-1)/2;
		int a,b;
		if(s%2==1){
			a=(s/2);
			b=a+1;
		}
		else{
			a=s/2;
			b=a+1;
			a--;
		}

		//cout<<a<<' '<<b<<endl;
		if(a>b)swap(a,b);
		add(a-1);
		nxt();
		add(a-1);
		nxt();
		add(b-1);
		nxt();
		add(b);
		if(fl==0)nxt();
		cout<<endl;
	}
		return 0;
}