#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            cnt++;
            i++;
        }
    }
    cout<<cnt/2<<endl;
    return 0;
}