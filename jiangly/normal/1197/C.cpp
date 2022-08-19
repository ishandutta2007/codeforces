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
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;++i){
        a[i]=a[i+1]-a[i];
    }
    a.pop_back();
    sort(a);
    ll ans=0;
    for(int i=0;i<n-k;++i){
        ans+=a[i];
    }
    printf("%I64d\n",ans);
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