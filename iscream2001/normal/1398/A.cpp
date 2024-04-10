#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=6e4+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	return ch;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int a[N];
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(a[1]+a[2]>a[n]) cout<<-1<<endl;
		else cout<<"1 2 "<<n<<endl;
	}
	return 0;
}