#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=501000,maxm=0,maxz=0;
int n,a[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void out(long long x){
    printf("%lld",x);
}
void out(string s){
    cout<<s;
}
void proc(){
    int n=read();
    int mni=0x3f3f3f3f,cnt=0;
    for(int i=0;i<n;++i){
        a[i]=read();
        if(mni>a[i]){
            mni=a[i];cnt=1;
        }
        else if(mni==a[i]){
            ++cnt;
        }
    }
    cout<<n-cnt<<endl;
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}