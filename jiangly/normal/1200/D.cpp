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
    int k=readInt();
    vector<string> s(n);
    vector<int> L(n,n),R(n,-1),U(n,n),D(n,-1);
    for(int i=0;i<n;++i){
        s[i]=readString();
        for(int j=0;j<n;++j){
            if(s[i][j]=='B'){
                L[i]=j;
                break;
            }
        }
        for(int j=n-1;j>=0;--j){
            if(s[i][j]=='B'){
                R[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(s[j][i]=='B'){
                U[i]=j;
                break;
            }
        }
        for(int j=n-1;j>=0;--j){
            if(s[j][i]=='B'){
                D[i]=j;
                break;
            }
        }
    }
    int ans=0;
    vector<vector<int>> cnt(n-k+1,vector<int>(n-k+1));
    for(int i=0;i+k-1<n;++i){
        int res=0;
        for(int j=0;j<k;++j){
            res+=(U[j]>=i&&D[j]<i+k);
        }
        for(int j=k;j<n;++j){
            res+=(D[j]==-1);
        }
        for(int j=0;j+k-1<n;++j){
            if(j>0){
                res-=(U[j-1]>=i&&D[j-1]<i+k);
                res+=(D[j-1]==-1);
                res-=(D[j+k-1]==-1);
                res+=(U[j+k-1]>=i&&D[j+k-1]<i+k);
            }
            cnt[i][j]=res;
        }
    }
    for(int i=0;i+k-1<n;++i){
        int res=0;
        for(int j=0;j<k;++j){
            res+=(L[j]>=i&&R[j]<i+k);
        }
        for(int j=k;j<n;++j){
            res+=(R[j]==-1);
        }
        for(int j=0;j+k-1<n;++j){
            if(j>0){
                res-=(L[j-1]>=i&&R[j-1]<i+k);
                res+=(R[j-1]==-1);
                res-=(R[j+k-1]==-1);
                res+=(L[j+k-1]>=i&&R[j+k-1]<i+k);
            }
            chkmax(ans,cnt[j][i]+res);
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