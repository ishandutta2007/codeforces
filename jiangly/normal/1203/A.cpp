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
    vector<int> a(n);
    for(int i=0;i<n;++i){
        a[i]=readInt()-1;
    }
    bool ok1=true,ok2=true;
    for(int i=0;i+1<n;++i){
        ok1&=((a[i]+1)%n==a[i+1]);
        ok2&=((a[i+1]+1)%n==a[i]);
    }
    if(ok1||ok2){
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
    solve_multiple_tests();
    return 0;
}