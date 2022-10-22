#include <bits/stdc++.h>3c
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long double> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<long double> b(n);
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    map<long double,int> k;
    int kol=0;

    for(int i=0;i<n;i++){
        if ((a[i])==0 && b[i]==0){
            kol++;
        }
        else if(a[i]==0){
            continue;
        }
        else{
            k[(-b[i])/a[i]]++;

        }
    }
    int ans=0;
    for(auto u:k){
        ans=max(ans,u.second);
        //cout << u.first << " " << u.second << endl;
    }
    cout << ans+kol;
}