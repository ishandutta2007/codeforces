#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
bool swp=false;
void out(int a,int b){
    a++;b++;
    if(!swp)cout<<a<<" "<<b<<endl;
    else cout<<b<<" "<<a<<endl;
    return;
}
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;
    y--;
    if(n>m){
        swp=true;
        swap(n,m);
        swap(x,y);
    }
    int row[n+5];
    for(int i=0;i<n;i++)row[i]=i;
    if(x==y)swap(row[x],row[x+1]);
    for(int i=0;i<n;i++){
        if(i==0)out(x,y);
        else out((x+i)%n,row[(x+i-1)%n]);
        for(int j=0;j<m;j++){
            if(row[(x+i)%n]==j)continue;
            if(i==0&&j==y)continue;
            if(i!=0&&j==row[(x+i-1)%n])continue;
            out((x+i)%n,j);
        }
        out((x+i)%n,row[(x+i)%n]);
    }
    return 0;
}