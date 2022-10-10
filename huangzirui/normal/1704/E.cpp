#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10010;
const ll mod=998244353;
int i,j,k,n,m;
ll a[maxn],d[maxn];
vector<int>e1[maxn],e2[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)e1[i].clear(),e2[i].clear();
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            e1[x].push_back(y);
            e2[y].push_back(x);
        }
        // cerr<<"OK!"<<endl;
        ll Ans=0;
        while(1){
            bool b=false;
            for(i=1;i<=n;i++)b|=a[i];
            if(!b)break;
            for(i=1;i<=n;i++)d[i]=(a[i]?-1:0);
            for(i=1;i<=n;i++)
                for(int j:e2[i])d[i]+=(a[j]!=0);
            ll Mt=1e18;
            for(i=1;i<=n;i++)
                if(d[i] && !a[i])Mt=1;
                else if(a[i] && d[i]<0)Mt=min(Mt,a[i]);
            for(i=1;i<=n;i++)a[i]+=d[i]*Mt;
            for(i=1;i<=n;i++)a[i]=(a[i]>=2*mod?(a[i]-mod)%mod+mod:a[i]);
            Ans+=Mt;
            // cerr<<"Ans="<<Ans<<endl;
            // for(i=1;i<=n;i++)cerr<<a[i]<<' ';cerr<<endl;
        }
        cout<<Ans%mod<<endl;
    }
}
/*
10 11
50 0 0 0 50 0 0 0 0 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 3
7 9

10 0 0 0 10 0 0 0 0 0
9 1 1 0 9 1 0 0 0 0
8 1 2 1 8 1 1 0 0 0
7 1 3 1 8 1 1 1 1 0
*/