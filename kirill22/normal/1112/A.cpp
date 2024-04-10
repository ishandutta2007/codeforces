#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(n);
    int used[m+10]={-1};
    for(int i=0;i<m+10;i++){
        used[i]=-1;
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        if (used[b[i]]==-1){
            used[b[i]]=i;
        }
        else{
            if (a[i]>a[used[b[i]]]){
                used[b[i]]=i;
            }
        }
    }
    int use[n+10];
    for(int i=0;i<n+10;i++){
        use[i]=0;
    }
    ll ans=0;
    vector<int> j(k);
    for(int i=0;i<k;i++){
        cin >> j[i];
        j[i]--;
        if (j[i]!=used[b[j[i]]]){
            ans++;
        }
    }
    cout << ans;
}