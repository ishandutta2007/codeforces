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
    int npos=1;
    for(int i=2;i<=n;i++){
        int x,y;
        cout<<"? "<<npos<<" "<<i<<endl;
        cin>>x;
        cout<<"? "<<i<<" "<<npos<<endl;
        cin>>y;
        if(y!=max(x,y)){
            arr[npos]=max(x,y);
            npos=i;
        }
        else arr[i]=max(x,y);
    }
    arr[npos]=n;
    cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<arr[i];
    cout<<endl;
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