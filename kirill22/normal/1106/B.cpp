#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,k,ans=0;
    cin >> n >> m;
    vector<pair<ll,pair<ll,ll>>> a(n);
    ll o=0;

    for(int i=0;i<n;i++){
        ll t;
        cin >> t;
        a[i].second.first=i;
        a[i].second.second=t;
    }
    for(int i=0;i<n;i++){
        ll t;
        cin >> t;
        a[i].first=t;
    }
    sort(a.begin(),a.end());
    int h=n;
    vector<int> index(n);
    for(int i=0;i<n;i++){
        ll f=a[i].second.first;

        index[f]=i;
    }


    for(int i=0;i<m;i++){
        ll t,d;
        cin >> t >> d;
        t--;
        int ii=index[t];


        if (a[ii].second.second>=d){
            a[ii].second.second-=d;
            cout << a[ii].first*d << endl;
            continue;
        }
        ll an=0;
        an+=a[ii].second.second*a[ii].first;
        d-=a[ii].second.second;
        a[ii].second.second=0;

        ii=o;
        bool f=true;
        while(d>0 && ii<n){
            if (a[ii].second.second>=d){
            a[ii].second.second-=d;
            cout << a[ii].first*d+an  << endl;
            f=false;
            break;
        }
        else{
                d-=a[ii].second.second;
            an+=a[ii].second.second*a[ii].first;
        a[ii].second.second=0;
        o++;

        }
        ii++;


        }

        if (f){
                if (d>0){
            cout << 0 << endl ;
            continue;
        }
        cout << an << endl;
        }

    }







}