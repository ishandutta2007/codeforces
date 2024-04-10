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
    const int P=1e9+7;
    int n;
    scanf("%d",&n);
    vector<int> x(n),y(n);
    vector<tuple<int,char,int>> q;
    for(int i=0;i<n;++i){
        scanf("%d%d",&y[i],&x[i]);
        q.emplace_back(x[i],1,i);
        q.emplace_back(y[i],0,i);
    }
    sort(q);
    vector<int> mn(n),cnt(n);
    int M=0,C=1,I=0;
    for(auto [x,op,id]:q){
        switch(op){
            case 1:
                chkmax(I,x);
                mn[id]=x+M;
                cnt[id]=C;
                break;
            case 0:
                if(-x+mn[id]<M){
                    M=-x+mn[id];
                    C=cnt[id];
                }else if(-x+mn[id]==M){
                    (C+=cnt[id])>=P?C-=P:0;
                }
                break;
        }
    }
    M=1e9;
    for(int i=0;i<n;++i){
        if(y[i]>I){
            if(mn[i]<M){
                M=mn[i];
                C=cnt[i];
            }else if(mn[i]==M){
                (C+=cnt[i])>=P?C-=P:0;
            }
        }
    }
    printf("%d\n",C);
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