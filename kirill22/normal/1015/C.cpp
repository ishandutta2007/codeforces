 #include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;

string s,t,rs,rt;
vector<int>ans;

 main() {
    cin >> n >> m;
    int sum=0,ans=0,ii=n-1;
    vector<int>a;
    for(int i=0;i<n;i++){
        int e,r;
        cin >> e >> r;
        a.push_back(e-r);
        sum+=e;
    }
    sort(a.begin(),a.end());
    while(sum>m){
        sum-=a[ii];
        ans++;
        ii--;
        if(ii<0){
            break;
        }
    }
    if (sum>m){
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}