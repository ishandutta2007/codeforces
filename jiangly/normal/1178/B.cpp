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
    string s;
    cin>>s;
    int n=s.length();
    vector<int> presum(n);
    vector<int> sufsum(n);
    int sum=0;
    for(int i=1;i<n;++i){
        sum+=s[i-1]=='v'&&s[i]=='v';
        presum[i]=sum;
    }
    sum=0;
    for(int i=n-2;i>=0;--i){
        sum+=s[i+1]=='v'&&s[i]=='v';
        sufsum[i]=sum;
    }
    ll ans=0;
    for(int i=2;i+2<n;++i){
        if(s[i]=='o'){
            ans+=1ll*presum[i-1]*sufsum[i+1];
        }
    }
    printf("%lld\n",ans);
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