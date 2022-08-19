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
    const int P=998244353;
    int n=readInt();
    set<string> string_set[11];
    for(int i=0;i<n;++i){
        string s=readString();
        string_set[s.length()].insert(s);
        reverse(s);
        string_set[s.length()].insert(s);
    }
    const auto id=[&](char c){
        if(islower(c)){
            return c-'a';
        }else if(isupper(c)){
            return c-'A'+26;
        }else{
            return c-'0'+52;
        }
    };
    const int p[]={24,12,12,4,12,6,4,1};
    int ans=0;
    for(int len=3;len<=10;++len){
        int cnt[62][62]={};
        for(string s:string_set[len]){
            ++cnt[id(s.front())][id(s.back())];
        }
        int f[62][62][62]={};
        for(int x=0;x<62;++x){
            for(int y=x;y<62;++y){
                for(int z=y;z<62;++z){
                    int res=0;
                    for(int i=0;i<62;++i){
                        res=(res+1ll*cnt[i][x]*cnt[i][y]%P*cnt[i][z])%P;
                    }
                    f[x][y][z]=res;
                }
            }
        }
        for(int a=0;a<62;++a){
            for(int b=a;b<62;++b){
                for(int c=b;c<62;++c){
                    for(int d=c;d<62;++d){
                        ans=(ans+1ll*f[a][b][c]*f[a][b][d]%P*f[a][c][d]%P*f[b][c][d]%P*p[(a==b)|(b==c)<<1|(c==d)<<2])%P;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
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