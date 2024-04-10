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
    int n,k,t;
    cin>>n>>k;
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>t;
        tot+=(k-t);
    }
    int zero=0;
    cout<<max(zero,(tot*2)-n)<<endl;
    return 0;
}