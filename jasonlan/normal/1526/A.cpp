#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
const int maxn=501000;
int n;
int a[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void proc(){
    n=read();
    for(int i=1;i<=(n<<1);++i)
        a[i]=read();
    sort(a+1,a+1+(n<<1));
    for(int i=1;i<=n;++i)
        cout<<a[i]<<' '<<a[n+i]<<' ';
    cout<<endl;
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}