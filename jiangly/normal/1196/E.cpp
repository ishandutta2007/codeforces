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
    const vector<int> dx{-1,1};
    int b,w,delta=0;
    scanf("%d%d",&b,&w);
    if(b>w){
        swap(b,w);
        ++delta;
    }
    if(w>3*b+1){
        puts("NO");
        return;
    }
    puts("YES");
    for(int i=1;i<=b*2;++i){
        printf("%d %d\n",3+delta,i);
    }
    int cnt=b;
    for(int y=2;y<=b*2&&cnt<w;y+=2){
        for(int i=0;i<2&&cnt<w;++i){
            ++cnt;
            printf("%d %d\n",3+delta+dx[i],y);
        }
    }
    if(cnt<w){
        printf("%d %d\n",3+delta,b*2+1);
    }
}
void solve_multiple_tests(){
    int tests;
    scanf("%d",&tests);
    for(int i=1;i<=tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_multiple_tests();
    return 0;
}