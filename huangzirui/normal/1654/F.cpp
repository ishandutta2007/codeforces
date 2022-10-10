#include<bits/stdc++.h>
using namespace std;
const int maxn=18,maxm=(1<<maxn)+5;
struct G{
    int id,X,Y;
};
bool cmp(G a,G b){
    return (a.X==b.X?a.Y<b.Y:a.X<b.X);
}
bool operator==(G a,G b){
    return a.X==b.X && a.Y==b.Y;
}
bool operator<(G a,G b){
    return a.X<b.X || (a.X==b.X && a.Y<b.Y);
}
int i,j,k,n,m,to[maxn+2][maxm],Rank[maxn+2][maxm];
G t[maxm],Sorter[maxm];int Len=0;
string S;
int main(){
    cin>>n;
    cin>>S;
    for(i=0;i<(1<<n);i++)to[0][i]=(i^1),Rank[0][i]=S[i]-'a'+1;
    for(i=1;i<=n;i++){
        for(j=0;j<(1<<n);j++){
            to[i][j]=to[i-1][to[i-1][j]]^(1<<i);
            t[j]=Sorter[j]={j,Rank[i-1][j],Rank[i-1][to[i-1][j]]};
            // cerr<<"j="<<j<<' '<<j<<' '<<Rank[i-1][j]<<' '<<Rank[i-1][to[i-1][j]]<<endl;
        }
        sort(Sorter,Sorter+(1<<n),cmp);
        // Len=unique(Sorter,Sorter+(1<<n))-Sorter;
        for(j=0;j<(1<<n);j++)
            Rank[i][j]=lower_bound(Sorter,Sorter+(1<<n),t[j])-Sorter+1;
        // for(j=0;j<(1<<n);j++)cerr<<i<<' '<<j<<' '<<to[i][j]<<' '<<Rank[i][j]<<endl;
    }
    int ans=1e9,chs=0;
    for(i=0;i<(1<<n);i++){
        if(Rank[n][i]<ans){
            ans=Rank[n][i];
            chs=i;
        }
    }
    for(i=0;i<(1<<n);i++)putchar(S[i^chs]);
    puts("");
}