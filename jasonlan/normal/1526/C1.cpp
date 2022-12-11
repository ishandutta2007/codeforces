#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
using namespace std;
const int maxn=810000;
int n;
int a[maxn];
priority_queue <int> s;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void proc(){
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    int cnt=0;
    long long psum=0;
    for(int i=1,p;i<=n;++i){
        if(a[i]>=0){
            psum+=a[i];++cnt;
        }
        else{
            if(psum+a[i]>=0){
                psum+=a[i];++cnt;
                s.push(-a[i]);
                continue;
            }
            if(!s.size())continue;
            if(s.top()+a[i]>=0){
                psum+=s.top()+a[i];
                s.pop();
                s.push(-a[i]);
            }
        }
    }
    cout<<cnt;
}
int main(){
    int T=1;
    while(T--)proc();
    return 0;
}