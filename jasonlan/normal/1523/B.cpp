#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const int maxn=401000;
int n,m;
queue <int>q;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void doop(int x,int y,int z){
    printf("%d %d %d\n",x,y,z);
}
void proc(){
    n=read();
    for(int i=1;i<=n;++i)read();
    cout<<(n>>1)*6<<endl;
    for(int i=1;i<=n;i+=2){
        doop(1,i,i+1);
        doop(2,i,i+1);
        doop(1,i,i+1);
        doop(1,i,i+1);
        doop(2,i,i+1);
        doop(1,i,i+1);
    }
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}