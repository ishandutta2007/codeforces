#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> niz[10000];
int main(){
    ios_base::sync_with_stdio(false);

    long long n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i].first>>niz[i].second;
    }
    sort(niz,niz+n);
    long long maxi=0;
    for(i=0;i<n;i++){
        if(niz[i].second>=maxi)maxi=niz[i].second;
        else maxi=niz[i].first;
    }
    cout<<maxi;
    return 0;
}