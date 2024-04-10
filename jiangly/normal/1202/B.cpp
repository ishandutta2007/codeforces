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
    const int N=10;
    string s=readString();
    int n=s.length();
    int d[N][N][N];
    memset(d,-1,sizeof(d));
    for(int x=0;x<N;++x){
        for(int y=0;y<N;++y){
            d[x][y][x]=0;
            d[x][y][y]=0;
            queue<int> que;
            que.push(x);
            if(x!=y){
                que.push(y);
            }
            while(!que.empty()){
                int u=que.front();
                que.pop();
                int v=(u+x)%N;
                if(d[x][y][v]==-1){
                    d[x][y][v]=d[x][y][u]+1;
                    que.push(v);
                }
                v=(u+y)%N;
                if(d[x][y][v]==-1){
                    d[x][y][v]=d[x][y][u]+1;
                    que.push(v);
                }
            }
        }
    }
    int ans[N][N]={};
    for(int i=0;i<n-1;++i){
        int t=(s[i+1]-s[i]+N)%N;
        for(int x=0;x<N;++x){
            for(int y=0;y<N;++y){
                if(d[x][y][t]!=-1&&ans[x][y]!=-1){
                    ans[x][y]+=d[x][y][t];
                }else{
                    ans[x][y]=-1;
                }
            }
        }
    }
    for(int x=0;x<N;++x){
        for(int y=0;y<N;++y){
            printf("%d ",ans[x][y]);
        }
        puts("");
    }
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