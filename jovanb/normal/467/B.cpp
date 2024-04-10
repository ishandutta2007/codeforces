#include <bits/stdc++.h>
using namespace std;

int k;
long long br[1005];

long long check(long long v){
    int z=0;
    while(v){
        if(v & 1)z++;
        v>>=1;
    }
    if(z<=k)return 1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,m,broj=0,i;
    cin>>n>>m>>k;
    for(i=0;i<=m;i++)cin>>br[i];
    for(i=0;i<m;i++){
        broj+=check(br[m]^br[i]);
    }
    cout<<broj;
    return 0;
}