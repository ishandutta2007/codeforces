#include <bits/stdc++.h>
using namespace std;

pair <long,long> per[10000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long s,n,i;
    cin>>s>>n;
    for(i=0;i<n;i++)cin>>per[i].first>>per[i].second;
    sort(per,per+n);
    for(i=0;i<n;i++){
        if(s>per[i].first)s+=per[i].second;
        else {cout<<"NO";return 0;}
    }
    cout<<"YES";
    return 0;
}