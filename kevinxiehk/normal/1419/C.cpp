#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n,x;
    cin>>n>>x;
    int arr[n+5],sum=0;
    int eqcnt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==x)eqcnt++;
        sum+=arr[i];
    }
    if(eqcnt==n){cout<<"0"<<endl;return;}
    if(sum==x*n||eqcnt>=2||(n==2&&eqcnt==1)){cout<<"1"<<endl;return;}
    else if(eqcnt==1){
        for(int i=0;i<=n-1;i++){
            if((sum-x*i)%(n-i)==0){cout<<"1"<<endl;return;}
        }
    }
    else cout<<"2"<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    cin>>t;
    
    while(t--)solve();
    return 0;
}