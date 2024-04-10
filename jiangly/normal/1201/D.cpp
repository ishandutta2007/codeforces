#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
int readInt(){
    int x=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
void solve_single_test(int test_id=1){
    int n=readInt();
    int m=readInt();
    int k=readInt();
    int q=readInt();
    vector<int> L(n,m);
    vector<int> R(n,-1);
    for(int i=0;i<k;++i){
        int x=readInt()-1;
        int y=readInt()-1;
        chkmin(L[x],y);
        chkmax(R[x],y);
    }
    vector<int> col(q);
    for(int &y:col){
        y=readInt()-1;
    }
    sort(col);
    vector<vector<ll>> dp(n,vector<ll>(2,1e18));
    L[0]=0;
    chkmax(R[0],0);
    dp[0][0]=R[0]*2;
    dp[0][1]=R[0];
    int last=0;
    for(int x=1;x<n;++x){
        if(L[x]!=m){
            for(int k=0;k<2;++k){
                int last_y=k==0?L[last]:R[last];
                ll last_cost=dp[last][k];
                if(last_y>=col.front()){
                    int y=*--upper_bound(col.begin(),col.end(),last_y);
                    chkmin(dp[x][0],last_cost+abs(last_y-y)+abs(y-R[x])+R[x]-L[x]);
                    chkmin(dp[x][1],last_cost+abs(last_y-y)+abs(y-L[x])+R[x]-L[x]);
                }
                if(last_y<=col.back()){
                    int y=*upper_bound(col.begin(),col.end(),last_y);
                    chkmin(dp[x][0],last_cost+abs(last_y-y)+abs(y-R[x])+R[x]-L[x]);
                    chkmin(dp[x][1],last_cost+abs(last_y-y)+abs(y-L[x])+R[x]-L[x]);
                }
            }
            last=x;
        }
    }
    printf("%lld\n",min(dp[last][0],dp[last][1])+last);
}
void solve_multiple_tests(){
    int n_tests;
    n_tests=readInt();
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}