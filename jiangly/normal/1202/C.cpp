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
    vector<int> preL(n),preR(n),preU(n),preD(n);
    vector<int> sufL(n),sufR(n),sufU(n),sufD(n);
    int L=0,R=0,U=0,D=0,x=0,y=0;
    for(int i=0;i<n;++i){
        switch(s[i]){
            case 'W':
                ++y;
                break;
            case 'A':
                --x;
                break;
            case 'S':
                --y;
                break;
            case 'D':
                ++x;
                break;
        }
        chkmax(R,x);
        chkmin(L,x);
        chkmax(U,y);
        chkmin(D,y);
        preL[i]=L-x;
        preR[i]=R-x;
        preU[i]=U-y;
        preD[i]=D-y;
    }
    L=0;
    R=0;
    U=0;
    D=0;
    x=0;
    y=0;
    for(int i=n-1;i>=0;--i){
        switch(s[i]){
            case 'W':
                --y;
                break;
            case 'A':
                ++x;
                break;
            case 'S':
                ++y;
                break;
            case 'D':
                --x;
                break;
        }
        chkmax(R,x);
        chkmin(L,x);
        chkmax(U,y);
        chkmin(D,y);
        sufL[i]=L-x;
        sufR[i]=R-x;
        sufU[i]=U-y;
        sufD[i]=D-y;
    }
    ll ans=1ll*(sufR[0]-sufL[0]+1)*(sufU[0]-sufD[0]+1);
    for(int i=0;i<n-1;++i){
        // printf("%d %d %d %d %d %d %d %d\n",preL[i],preR[i],preU[i],preD[i],sufL[i+1],sufR[i+1],sufU[i+1],sufD[i+1]);
        // printf("%d R %I64d\n",i,1ll*(max(preR[i],sufR[i+1]+1)-min(preL[i],sufL[i+1]+1)+1)*(max(preU[i],sufU[i+1])-min(preD[i],sufD[i+1])+1));
        chkmin(ans,1ll*(max(preR[i],sufR[i+1]+1)-min(preL[i],sufL[i+1]+1)+1)*(max(preU[i],sufU[i+1])-min(preD[i],sufD[i+1])+1));
        // printf("%d L %I64d\n",i,1ll*(max(preR[i],sufR[i+1]-1)-min(preL[i],sufL[i+1]-1)+1)*(max(preU[i],sufU[i+1])-min(preD[i],sufD[i+1])+1));
        chkmin(ans,1ll*(max(preR[i],sufR[i+1]-1)-min(preL[i],sufL[i+1]-1)+1)*(max(preU[i],sufU[i+1])-min(preD[i],sufD[i+1])+1));
        // printf("%d L %I64d\n",i,1ll*(max(preR[i],sufR[i+1])-min(preL[i],sufL[i+1])+1)*(max(preU[i],sufU[i+1]+1)-min(preD[i],sufD[i+1]+1)+1));
        chkmin(ans,1ll*(max(preR[i],sufR[i+1])-min(preL[i],sufL[i+1])+1)*(max(preU[i],sufU[i+1]+1)-min(preD[i],sufD[i+1]+1)+1));
        // printf("%d L %I64d\n",i,1ll*(max(preR[i],sufR[i+1])-min(preL[i],sufL[i+1])+1)*(max(preU[i],sufU[i+1]-1)-min(preD[i],sufD[i+1]-1)+1));
        chkmin(ans,1ll*(max(preR[i],sufR[i+1])-min(preL[i],sufL[i+1])+1)*(max(preU[i],sufU[i+1]-1)-min(preD[i],sufD[i+1]-1)+1));
    }
    printf("%I64d\n",ans);
}
void solve_multiple_tests(){
    int n_tests;
    scanf("%d",&n_tests);
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_multiple_tests();
    return 0;
}