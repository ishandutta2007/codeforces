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
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[0]+arr[1]>arr[n-1])cout<<"-1"<<endl;
    else cout<<1<<" "<<2<<" "<<n<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}