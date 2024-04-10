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
    string s=readString();
    int n=s.length();
    string ans;
    for(int i=0;i<n/4;++i){
        if(s[i*2]==s[n-i*2-1]||s[i*2]==s[n-i*2-2]){
            ans+=s[i*2];
        }else{
            ans+=s[i*2+1];
        }
    }
    if(n%4>=2){
        ans+=s[n/2];
    }
    for(int i=n/4-1;i>=0;--i){
        ans+=ans[i];
    }
    puts(ans.c_str());
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