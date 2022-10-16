#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n==1){
        cout<<"1 1"<<endl<<arr[0]*-1<<endl<<"1 1"<<endl<<arr[0]<<endl<<"1 1"<<endl<<arr[0]*-1<<endl;
        return;
    }
    int pos[n+5];
    for(int i=0;i<n;i++){
        if(arr[i]<0)pos[i]=-1;
        else pos[i]=1;
        arr[i]=abs(arr[i]);
    }
    int t[n+5];
    for(int i=0;i<n;i++){
        t[i]=arr[i]%(n-1);
        t[i]=(n-1)-t[i];
    }
    cout<<"1 "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<t[i]*n*pos[i]<<" ";
        arr[i]+=t[i]*n;
    }
    cout<<endl<<"1 "<<n-1<<endl;
    for(int i=0;i<n-1;i++){
        cout<<arr[i]*pos[i]*-1<<" ";
    }
    cout<<endl<<n<<" "<<n<<endl;
    cout<<arr[n-1]*pos[n-1]*-1<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    //cin>>t;
    
    while(t--)solve();
    return 0;
}