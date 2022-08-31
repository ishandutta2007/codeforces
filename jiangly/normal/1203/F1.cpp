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
template<class T>void reverse(vector<T> &a){
    reverse(a.begin(),a.end());
}
void reverse(string &a){
    reverse(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
int readInt(){
    int x=0;
    bool sign=false;
    char c=getchar();
    while(!isdigit(c)){
        sign=c=='-';
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return sign?-x:x;
}
ll readLong(){
    ll x=0;
    bool sign=false;
    char c=getchar();
    while(!isdigit(c)){
        sign=c=='-';
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return sign?-x:x;
}
string readString(){
    string s;
    char c=getchar();
    while(isspace(c)){
        c=getchar();
    }
    while(!isspace(c)){
        s+=c;
        c=getchar();
    }
    return s;
}
void solve_single_test(int test_id=1){
    int n=readInt();
    int r=readInt();
    vector<pair<int,int>> pos,neg;
    for(int i=0;i<n;++i){
        int a=readInt();
        int b=readInt();
        if(b>=0){
            pos.emplace_back(a,b);
        }else{
            neg.emplace_back(a+b,a);
        }
    }
    int ans=0;
    sort(pos);
    sort(neg);
    reverse(neg);
    for(auto [a,b]:pos){
        if(a>r){
            break;
        }
        ++ans;
        r+=b;
    }
    vector<int> dp(r+1,-1e9);
    dp[r]=ans;
    for(auto [b,a]:neg){
        b-=a;
        for(int i=max(a,-b);i<=r;++i){
            chkmax(dp[i+b],dp[i]+1);
        }
    }
    ans=0;
    for(int i=0;i<=r;++i){
        chkmax(ans,dp[i]);
    }
    // printf("%d\n",ans);
    if(ans==n){
        puts("YES");
    }else{
        puts("NO");
    }
}
void solve_multiple_tests(){
    int n_tests=readInt();
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}