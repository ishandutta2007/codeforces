#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int maxn=501,maxm=0,mod=0;
int n;
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
int qdec(int x){
    return x<0?x+mod:x;
}
void proc(){
    string s;
    cin>>s;
    int t=0;
    for(int i=0;i<s.length();++i)
        t=max(t,s[i]-'0');
    printf("%d\n",t);
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}