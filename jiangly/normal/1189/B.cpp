// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[n-1]>=a[n-2]+a[n-3]){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=n&1;i<n;i+=2){
            cout<<a[i]<<' ';
        }
        for(int i=n-1;i>=0;i-=2){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}