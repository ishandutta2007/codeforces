// luogu remote judge
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
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    for(int i=0;i<n;++i){
        char c;
        scanf(" %c",&c);
        switch(c){
            case 'R':
                a[i]=(-i%3+3)%3;
                break;
            case 'G':
                a[i]=((1-i)%3+3)%3;
                break;
            case 'B':
                a[i]=((2-i)%3+3)%3;
                break;
        }
        fprintf(stderr,"%d ",a[i]);
    }
    fputs("",stderr);
    vector<int> cnt(3);
    for(int i=0;i<k-1;++i){
        ++cnt[a[i]];
    }
    int ans=n;
    for(int i=k-1;i<n;++i){
        ++cnt[a[i]];
        fprintf(stderr,"%d %d %d\n",cnt[0],cnt[1],cnt[2]);
        chkmin(ans,k-max(cnt[0],max(cnt[1],cnt[2])));
        --cnt[a[i-k+1]];
    }
    printf("%d\n",ans);
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