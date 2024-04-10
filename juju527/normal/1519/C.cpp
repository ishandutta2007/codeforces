#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int b[maxn];
vector<int>s[maxn];
ll res[maxn],c[maxn];
int main(){
    int T;
    T=read();
    while(T--){
        int n;
        n=read();
        for(int i=1;i<=n;i++)b[i]=read();
        for(int i=1;i<=n;i++)s[b[i]].push_back(read());
        for(int i=1;i<=n;i++)res[i]=c[i]=0;
        ll S=0;
        for(int i=1;i<=n;i++){
            int len=s[i].size();
            ll sum=0;
            sort(s[i].begin(),s[i].end());
            for(int j=0;j<=len;j++){
                int x=len-j;
                for(int y=1;y<=sqrt(x);y++){
                    if(x%y)continue;
                    if(y>j)res[y]-=sum;
                    if(((x/y)!=y)&&((x/y)>j))res[x/y]-=sum;
                }
                if(j<len)sum+=s[i][j];
            }
            S+=sum;
            c[1]+=sum;c[len+1]-=sum;
            s[i].clear();
        }
        for(int i=1;i<=n;i++)c[i]+=c[i-1];
        for(int i=1;i<=n;i++)printf("%lld ",res[i]+c[i]);
        puts("");
    }
    return 0;
}