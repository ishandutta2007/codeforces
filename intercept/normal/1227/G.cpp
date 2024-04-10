#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=1e3+9;
int n,tot;
int a[M],id[M];
bool ans[M];
bool b[M][M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        id[i]=i;
        scanf("%d",&a[i]);
    }
    sort(id+1,id+n+1,[&](const int&l,const int&r){return a[l]>a[r];});
    for(int x=1;x<=n;++x){
        int i=id[x],r=x;
        if(a[id[x+1]]==0||a[i]==1)break;
        memset(ans,0,sizeof(ans));
        for(int j=x;j<=n;++j){
            if(a[id[j]]==a[i])ans[id[j]]=1,r=j;
        }
        for(int j=1;j<x;++j){
            ans[id[j]]=1;
        }
        if(r==x){
            int t=n;
            while(r==x&&a[id[x+1]]){
                if(!a[id[t]])t--;
                else{
                    ans[id[t]]=1;
                    ++tot;
                    for(int j=1;j<=n;++j)b[tot][j]=ans[j];
                    for(int j=1;j<=n;++j)a[j]-=ans[j];
                    ans[id[t]]=0;
                    t--;
                    while(a[i]==a[id[r+1]])r++,ans[id[r]]=1;
                }
            }
        }
        if(a[id[x+1]]==0)break;
        ans[i]=0;
        ++tot;
        for(int j=1;j<=n;++j)b[tot][j]=ans[j];
        for(int j=1;j<=n;++j)a[j]-=ans[j];
    }
    while(a[id[1]]){
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;++i){
            if(a[i])ans[i]=1;
        }
        ++tot;
        for(int j=1;j<=n;++j)b[tot][j]=ans[j];
        for(int j=1;j<=n;++j)a[j]-=ans[j];
    }
    cout<<tot<<endl;
    for(int i=1;i<=tot;++i){
        for(int j=1;j<=n;++j)putchar(b[i][j]?'1':'0');
        puts("");
    }
    return 0;
}
/*
6
6 6 5 5 2 2 

*/