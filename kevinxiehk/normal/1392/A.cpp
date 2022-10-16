#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    bool allsame=true;
    for(int i=1;i<n;i++)if(arr[i]!=arr[i-1])allsame=false;
    if(allsame)cout<<n<<endl;
    else cout<<1<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}