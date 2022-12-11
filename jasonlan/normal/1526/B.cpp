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
const int maxn=1e7;
int n;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void proc(){
    n=read();
    for(int i=0;i<12;++i){
        if(n%11==0){
            puts("YES");return;
        }
        n-=111;
        if(n<0)break;
    }
    puts("NO");
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}