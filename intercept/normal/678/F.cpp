#include<bits/stdc++.h>
#define ll long long
#define pii pair<double,int>
#define fi first
#define se second
using namespace std;
const int M=3e5+9;
const int B=509;
int n,m,top,num;
int id[M];
struct P{
    int o,k,b,x,d;
}p[M];
set<int>a,e;
bool vis[M];
pii s[M];
ll ans[M];
ll val(int x,int i){
    return 1ll*p[i].k*x+p[i].b;
}
void add(){
    top=0;
    for(int o=1;o<=m;++o){
        int i=id[o];
        if(!vis[i])continue;
        if(!top){
            s[++top]={-1e9,i};
            continue;
        }
        if(val(1e9,s[top].se)>=val(1e9,i))continue;
        while(top&&val(s[top].fi,s[top].se)<=val(s[top].fi,i))top--;
        if(!top){
            s[++top]={-1e9,i};
            continue;
        }
        pii t={1.0*(p[i].b-p[s[top].se].b)/(p[s[top].se].k-p[i].k),i};
        s[++top]=t;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&p[i].o);
        if(p[i].o==1){
            scanf("%d%d",&p[i].k,&p[i].b);
            id[++m]=i;
        }
        if(p[i].o==2){
            scanf("%d",&p[i].d);
        }
        if(p[i].o==3){
            scanf("%d",&p[i].x);
        }
    }
    sort(id+1,id+m+1,[&](const int&l,const int&r){return p[l].k<p[r].k;});
    for(int l=1;l<=n;l+=B){
        int r=l+B-1;
        e.clear();
        a.clear();
        for(int i=l;i<=r;++i){
            if(p[i].o==2&&vis[p[i].d]){
                e.insert(p[i].d);
                vis[p[i].d]=0;
            }
        }
        add();
        for(int i=l;i<=r;++i){
            if(p[i].o==1){
                a.insert(i);
                vis[i]=1;
            } 
            if(p[i].o==2){
                if(vis[p[i].d]==0){
                    e.erase(p[i].d);
                }
                else vis[p[i].d]=0,a.erase(p[i].d);
            }
            if(p[i].o==3){
                num++;
                ans[num]=-1ll<<60;
                if(top){
                    auto t=upper_bound(s+1,s+top+1,make_pair(1.0*p[i].x,0))-s-1;
                    ans[num]=val(p[i].x,s[t].se);
                }
                for(auto o:a)ans[num]=max(ans[num],val(p[i].x,o));
                for(auto o:e)ans[num]=max(ans[num],val(p[i].x,o));
            }
        }
    }
    for(int i=1;i<=num;++i){
        if(ans[i]==-1ll<<60)puts("EMPTY SET");
        else printf("%lld\n",ans[i]);
    }
    return 0;
}
/*
4
1 2 3
1 -1 100
2 2
3 1

*/