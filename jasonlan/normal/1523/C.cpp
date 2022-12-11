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
const int maxn=1010;
int n,m;
int a[maxn];
vector<int> v;
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
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<=n;++i){
        if(a[i]==1)
            v.push_back(1);
        else{
            while(v.size()&&v[v.size()-1]!=a[i]-1)
                v.pop_back();
            ++v[v.size()-1];
        }
        for(int i=0;i<v.size()-1;++i)
            cout<<v[i]<<'.';
        cout<<v[v.size()-1]<<endl;
    }
    v.clear();
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}