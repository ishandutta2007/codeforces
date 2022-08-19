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
    int limit=n*3/2;
    vector<bool> is_prime(limit+1,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2;i<=limit;++i){
        if(is_prime[i]){
            for(int k=i+i;k<=limit;k+=i){
                is_prime[k]=false;
            }
        }
    }
    vector<pair<int,int>> edges;
    for(int i=0;i<n;++i){
        edges.emplace_back(i,(i+1)%n);
    }
    int cur=0;
    while(!is_prime[edges.size()]){
        edges.emplace_back(cur,cur+n/2);
        ++cur;
    }
    printf("%d\n",(int)edges.size());
    for(auto [u,v]:edges){
        printf("%d %d\n",u+1,v+1);
    }
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