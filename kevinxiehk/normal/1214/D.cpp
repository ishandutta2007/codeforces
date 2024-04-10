#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int v[1000100];
int n,m;
bool vi[1000100][3];
int lol(int a,int b){
    return (a-1)*m+b-1;
}
void bfs(int a,int b,int d){
    
    if(a<=0||b<=0)return;
    if(a>n||b>m)return;
    if(v[lol(a,b)]==-1)return;
    if(vi[lol(a,b)][d+1])return;
  //  cout<<d<<" "<<a<<" "<<b<<endl;
    v[lol(a,b)]++;
    vi[lol(a,b)][d+1]=true;
    bfs(a+d,b,d);
    bfs(a,b+d,d);
    return;
}
int main(){
    char c;
    cin>>n>>m;
    
    for(int i=0;i<n*m;i++){
        cin>>c;
        if(c=='.')v[i]=0;
        else v[i]=-1;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<v[lol(i,j)]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<v[lol(3,2)]<<endl;
    for(int i=0;i<n*m;i++){for(int j=0;j<=2;j++){if(v[i]==0)vi[i][j]=false;else vi[i][j]=true;}}
    bfs(1,1,1);
    bfs(n,m,-1);
    //  for(int i=1;i<=n;i++){
    //      for(int j=1;j<=m;j++){
    //          cout<<v[lol(i,j)]<<" ";
    //      }
    //      cout<<endl;
    //  }
    int cnt=0,mincnt=9999999;
    for(int i=3;i<=n+m-1;i++){
        cnt=0;
        for(int j=max(1,i-m);j<=min(i-1,n);j++){
            if(j>n||i-j>m)continue;
            if(v[lol(j,i-j)]==2)cnt++;
        }
        mincnt=min(mincnt,cnt);
        //cout<<i<<" "<<cnt<<endl;
    }
    cout<<min(mincnt,2)<<endl;
   // cout<<v[lol(3,2)]<<endl;
    return 0;
}