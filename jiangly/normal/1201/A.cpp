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
    int n,m;
    n=readInt();
    m=readInt();
    string answer;
    vector<vector<int>> cnt(m,vector<int>(5));
    for(int i=1;i<=n;++i){
        cin>>answer;
        for(int j=0;j<m;++j){
            ++cnt[j][answer[j]-'A'];
        }
    }
    int total=0;
    for(int i=0;i<m;++i){
        int mx=0;
        for(int j=0;j<5;++j){
            chkmax(mx,cnt[i][j]);
        }
        int score=readInt();
        total+=mx*score;
    }
    printf("%d\n",total);
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