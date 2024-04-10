#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=2e5+5;
char s[maxn],t[maxn];
bool b[maxn];
vector<int> pos[10];
int main(){
    int tt;
    int i,n;
    int p,las;
    bool flg;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%s",&n,s);
        for (i=0;s[i];i++) b[i]=0;
        for (i=0;i<10;i++) pos[i].clear();
        for (i=0;i<n;i++) pos[s[i]-'0'].push_back(i);
        las=n; flg=true;
        for (i=9;i>=0;i--) if (flg&&pos[i].size()){
            for (auto p:pos[i]){
                if (p>las){
                    flg=false; break;
                }
                b[p]=1;
            }
            las=pos[i][0];
        }
        p=0;
        for (i=0;i<n;i++) if (!b[i])
            t[p++]=s[i];
        p=n-1;
        for (i=n-1;i>=0;i--) if (b[i])
            t[p--]=s[i];
        t[n]=0;
        flg=true;
        for (i=1;flg&&i<n;i++) if (t[i]<t[i-1])
            flg=false;
        if (!flg){
            puts("-"); continue;
        }
        for (i=0;i<n;i++) printf("%d",b[i]+1);
        puts("");
    }
    return 0;
}