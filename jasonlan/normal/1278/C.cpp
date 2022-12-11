#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn=200100;
int n;
int x[maxn];
map <int,int> mp;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
    int T=read();
    while(T--){
        mp.clear();
        n=read();
        for(register int i=1;i<=(n<<1);++i){
            x[i]=read()&1?1:-1;
            x[i]+=x[i-1];
        }
        for(register int i=0;i<=n;++i)
            mp[x[i]]=i;
        int ans=n<<1;
        for(register int i=n,a;i<=(n<<1);++i){
            a=x[i]-x[n<<1];
            if(mp.count(a))ans=min(ans,i-mp[a]);
        }
        cout<<ans<<endl;
    }
	return 0;
}