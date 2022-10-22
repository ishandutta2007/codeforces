#include <bits/stdc++.h>
using namespace std;

bool rev(const pair<int,int> &a,  
               const pair<int,int> &b) { 
    return (a.first > b.first); 
}
int main(){
    int n,k;
    cin >> n;
    pair<int,int> a[n];
    for (int i = 0; i < n; i++){
        cin >> k;
        a[i] = {k, i+1};
    }
    sort(a, a+n, rev);
    long ans=0;
    for (int i = 0; i < n; i++){
        ans += i*a[i].first+1;
    }
    cout << ans << endl;
    for (auto p:a) cout << p.second << ' ';
    
}