#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    string arr[n+5];
    string arr2[m+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>arr2[i];
    int q;
    cin>>q;
    int t;
    for(int i=0;i<q;i++){
        cin>>t;
        cout<<arr[(t-1)%n]<<arr2[(t-1)%m]<<endl;
    }
    return 0;
}