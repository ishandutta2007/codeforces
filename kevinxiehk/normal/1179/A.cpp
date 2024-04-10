#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[n+5];
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    int bk[n+5];
    int cnt=0;
    int a,b=arr[0];
    pair<int,int>fnt[n+5];
    for(int i=1;i<n;i++){
        a=arr[i];
        bk[i]=min(a,b);
        fnt[i]=mp(b,a);
        b=max(a,b);
    }
    bk[0]=bk[n-1];
    long long t;
    for(int i=0;i<m;i++){
        cin>>t;
        if(t<=n-1){
            cout<<fnt[t].fi<<" "<<fnt[t].se<<endl;
        }
        else cout<<b<<" "<<bk[t%(n-1)]<<endl;
    }
    return 0;
}