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
    int sum=0;
    bool alleven=true;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]%2)alleven=false;
    }
    if(sum%2==1){cout<<"First"<<endl;return 0;}
    else if(alleven)cout<<"Second"<<endl;
    else cout<<"First"<<endl;
    return 0;
}