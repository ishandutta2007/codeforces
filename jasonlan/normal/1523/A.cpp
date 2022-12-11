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
void proc(){
    n=read();m=read();
    string s;
    cin>>s;
    m=min(n,m);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(s[j]=='1')continue;
            if((j!=0&&s[j-1]=='1')+(j!=n-1&&s[j+1]=='1')==1){
                q.push(j);
            }
        }
        while(q.size())
            s[q.front()]='1',q.pop();
    }
    cout<<s<<endl;
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}