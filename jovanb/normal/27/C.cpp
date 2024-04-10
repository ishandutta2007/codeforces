#include <bits/stdc++.h>
using namespace std;

long long niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,maxi=-10000000,mini=10000000,indmax=0,indmin=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    for(i=0;i<n;i++){
        if(niz[i]<maxi && maxi>mini && indmax>indmin){cout<<"3\n"<<indmin+1<<" "<<indmax+1<<" "<<i+1;return 0;}
        if(niz[i]>mini && maxi>mini && indmax<indmin){cout<<"3\n"<<indmax+1<<" "<<indmin+1<<" "<<i+1;return 0;}
        if(maxi<niz[i]){maxi=niz[i];indmax=i;}
        if(mini>niz[i]){mini=niz[i];indmin=i;}
    }
    cout<<0;
    return 0;
}