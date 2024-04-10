#include <bits/stdc++.h>
using namespace std;

int niz[1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,x,i,br=0;
    cin>>n;
    cin>>x;
    n--;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    sort(niz,niz+n);
    while(x<=niz[n-1]){
        x++;
        niz[n-1]--;
        br++;
        sort(niz,niz+n);
    }
    cout<<br;
    return 0;
}