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
        x=x*10+c-'0';
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
    int a=readInt();
    int b=readInt();
    int n=a+b;
    int ans=0;
    for(int l=1,r;l<=n;l=r+1){
        int t=n/l;
        r=n/t;
        if((a+t)/(t+1)>a/t||(b+t)/(t+1)>b/t){
            continue;
        }
        int L=max(l,(a+t)/(t+1)+(b+t)/(t+1));
        int R=min(r,a/t+b/t)+1;
        if(L<R){
            ans+=R-L;
        }
    }
    printf("%d\n",ans);
}
void solve_multiple_tests(){
    int n_tests;
    scanf("%d",&n_tests);
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}