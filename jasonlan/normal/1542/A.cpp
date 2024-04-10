#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=110;
int n;
int a[maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
void proc(){
    n=read();
    int c[2];c[0]=c[1]=0;
    for(int i=1;i<=(n<<1);++i)
        c[read()%2]++;
    if(c[0]==c[1])puts("Yes");
    else puts("No");
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}