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
    int n=readInt();
    int my_seats=readInt();
    int total=my_seats;
    int my_total=my_seats;
    vector<int> parties{1};
    for(int i=2;i<=n;++i){
        int seats=readInt();
        total+=seats;
        if(seats*2<=my_seats){
            my_total+=seats;
            parties.push_back(i);
        }
    }
    if(my_total*2>total){
        printf("%d\n",(int)parties.size());
        for(int i:parties){
            printf("%d ",i);
        }
    }else{
        puts("0");
    }
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