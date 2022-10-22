#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> par[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,br=0,r,l,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>par[i].first>>par[i].second;
    }
    sort(par,par+n);
    l=par[0].first;
    r=par[0].second;
    for(i=1;i<n;i++){
        if(par[i].first>l && par[i].second<r)br++;
        else{
            l=par[i].first;
            r=par[i].second;
        }
    }
    cout<<br;
    return 0;
}