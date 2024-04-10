// luogu remote judge
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
void solve_single_test(int test_id=1){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<vector<pair<int,int>>> e(n);
    for(int i=0;i<m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        --u;
        --v;
        e[u].emplace_back(w,v);
        e[v].emplace_back(w,u);
    }
    for(int i=0;i<n;++i){
        sort(e[i]);
    }
    vector<set<int>> used(n);
    priority_queue<tuple<ll,int,int,int>> h;
    for(int i=0;i<n;++i){
        used[i].insert(i);
        h.emplace(-e[i][0].first,i,i,0);
    }
    k<<=1;
    int cnt=0;
    while(true){
        auto x=h.top();
        h.pop();
        ll dis=-get<0>(x);
        int u=get<1>(x);
        int v=get<2>(x);
        int id=get<3>(x);
        int y=e[v][id].second;
        if(!used[u].count(y)){
            ++cnt;
            used[u].insert(y);
            if(cnt==k){
                printf("%lld\n",dis);
                return;
            }
            h.emplace(-dis-e[y][0].first,u,y,0);
        }
        if(id+1<e[v].size()){
            h.emplace(-dis+e[v][id].first-e[v][id+1].first,u,v,id+1);
        }
    }
}
void solve_multiple_tests(){
    int tests;
    scanf("%d",&tests);
    for(int i=1;i<=tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}