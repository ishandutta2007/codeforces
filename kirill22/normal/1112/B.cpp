#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long double n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int,pair<int,int> > > m(k,{0,{0,-1}});
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long double kol=0;
    long double d=0;
    int ii=0;
    int ans=0;
    vector<int> jop(n+5);
    for(int i=0;i<n+5;i++){
        jop[i]=0;
    }
    while(kol!=n){
        for(int i=0;i<k;i++){
            m[i].first++;
            if (m[i].first==m[i].second.first || m[i].second.first==0){
                if (m[i].second.first!=0){
                    kol++;
                    long double h=100;
                    d=round(100*kol/n);


                }
                if (ii!=n){
                    m[i].first=0;
                    m[i].second.first=a[ii];
                    m[i].second.second=ii;
                    ii++;

                }
                else{
                    m[i].second.first=0;
                    m[i].first=0;
                    m[i].second.second =  -1;
                }
            }

        }
        for(int i=0;i<k;i++){
            if (m[i].first+1==d){
                    if (m[i].second.second>=0 && jop[m[i].second.second]==0){
                        ans++;
                        jop[m[i].second.second]=1;
                    }


                }
        }




    }

    cout << ans;
}