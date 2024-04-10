#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int h,n;
    cin>>h>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    arr[n]=0;
    arr[0]=arr[1]+1;
    int now=arr[0];
    int pos=1;
    int cnt=0;
    while(pos<n){
        if(arr[pos+1]<=now-3){
            cnt++;
            pos++;
            now=arr[pos]+1;
        }
        else{
            pos+=2;
            now=arr[pos]+1;
        }
    }
    cout<<cnt<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}