#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+10;
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
char s[N];
map<int,int> c;
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		LL ans=0;
		cin>>n;
		c.clear();
		c[0]=1;
		scanf("%s",s+1);
		for(int i=1;i<=n;++i){
			a[i]=s[i]-'0';
			a[i]--;
			a[i]=a[i-1]+a[i];
			ans+=(LL)c[a[i]]; 
			++c[a[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}