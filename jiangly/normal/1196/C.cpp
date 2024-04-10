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
    int n;
    scanf("%d",&n);
    int mx=-1e5,my=-1e5,Mx=1e5,My=1e5;
    for(int i=0;i<n;++i){
        int x,y,f1,f2,f3,f4;
        scanf("%d%d%d%d%d%d",&x,&y,&f1,&f2,&f3,&f4);
        if(!f1){
            chkmax(mx,x);
        }
        if(!f2){
            chkmin(My,y);
        }
        if(!f3){
            chkmin(Mx,x);
        }
        if(!f4){
            chkmax(my,y);
        }
    }
    fprintf(stderr,"%d %d %d %d\n",mx,Mx,my,My);
    if(mx<=Mx&&my<=My){
        printf("1 %d %d\n",mx,my);
    }else{
        puts("0");
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