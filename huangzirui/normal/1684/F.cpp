#include<bits/stdc++.h>
#define Mid ((L+R)>>1)
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
const int maxn=200010;
struct node{
    int L,R;
}d[maxn],s[maxn];
bool cmp(node a,node b){
    return a.L<b.L || (a.L==b.L && a.R>b.R);
}
int i,j,k,n,m,a[maxn],b[maxn];
set<int>St[maxn],tu;
vector<int>V[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){tu.clear();
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+1+n);
        for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+1+n,a[i])-b;
        for(i=1;i<=m;i++){
            int L,R;
            scanf("%d%d",&L,&R);
            d[i]={L,R};
        }
        // cerr<<"OK"<<endl;
        sort(d+1,d+1+m,cmp);
        int lst=d[1].R;s[1]=d[1];int cnt=1;
        // cerr<<"OK"<<endl;
        for(i=2;i<=m;i++)
            if(d[i].R>lst)s[++cnt]=d[i],lst=d[i].R;
        m=cnt;
        int tL=1,tR=0,Min=n,ls=0,Max=0;
        // cerr<<"OK"<<endl;
        for(i=1;i<=m;i++){
            // cerr<<"i="<<i<<' '<<s[i].L<<' '<<s[i].R<<endl;
            while(tR<s[i].R){
                ++tR;
                St[a[tR]].insert(tR);
            }
            while(tL<s[i].L){
                St[a[tL]].erase(tL);
                ++tL;
            }
            for(ls++;ls<=tR;ls++){
                if(St[a[ls]].size()>=2){
                    // cerr<<"ls="<<ls<<' '<<(*(--(--St[a[ls]].end())))<<endl;
                    Max=max(Max,*(--(--St[a[ls]].end())));
                    V[(*St[a[ls]].begin())+1].push_back(*(--St[a[ls]].end()));
                    Min=min(Min,*(++St[a[ls]].begin()));
                }
            }ls=tR;
        }
        if(!Max){
            puts("0");
            for(i=1;i<=n+1;i++)V[i].clear();
            for(i=1;i<=n;i++)St[a[i]].clear();
            continue;
        }
        int Ans=1e9;
        for(i=1;i<=Min;i++){
            for(auto w:V[i])Max=max(Max,w);
            // cerr<<i<<' '<<Max<<endl;
            Ans=min(Ans,Max-i+1);
        }cout<<Ans<<endl;
        for(i=1;i<=n+1;i++)V[i].clear();
        for(i=1;i<=n;i++)St[a[i]].clear();
    }
}
/*
100
5 3
1 1 1 1 1
1 3
2 4
3 5
*/