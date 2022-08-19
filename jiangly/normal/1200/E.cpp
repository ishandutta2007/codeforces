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
int id(char c){
    if(isupper(c)){
        return c-'A'+1;
    }else if(islower(c)){
        return c-'a'+27;
    }else{
        return c-'0'+53;
    }
}
void solve_single_test(int test_id=1){
    const ll P1=1e14+31,P2=1e14+67;
    const int BASE=131;
    int n=readInt();
    ll p1[1000001],p2[1000001];
    p1[0]=1;
    p2[0]=1;
    for(int i=1;i<=1000000;++i){
        p1[i]=p1[i-1]*BASE%P1;
        p2[i]=p2[i-1]*BASE%P2;
    }
    string s,t;
    while(n--){
        t=readString();
        ll hs1=0,hs2=0;
        ll ht1=0,ht2=0;
        int len=0;
        for(int i=1;i<=s.length()&&i<=t.length();++i){
            hs1=(hs1+id(s[s.length()-i])*p1[i-1])%P1;
            hs2=(hs2+id(s[s.length()-i])*p2[i-1])%P2;
            ht1=(ht1*BASE+id(t[i-1]))%P1;
            ht2=(ht2*BASE+id(t[i-1]))%P2;
            if(hs1==ht1&&hs2==ht2){
                chkmax(len,i);
            }
        }
        s+=t.substr(len,t.length()-len);
    }
    puts(s.c_str());
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