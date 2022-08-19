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
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    int pos;
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        if(a[i]==n){
            pos=i;
        }
    }
    for(int i=0;i<pos;++i){
        if(a[i]>a[i+1]){
            puts("NO");
            return;
        }
    }
    for(int i=pos;i+1<n;++i){
        if(a[i]<a[i+1]){
            puts("NO");
            return;
        }
    }
    puts("YES");
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