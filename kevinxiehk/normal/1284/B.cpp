#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool info[n+5];
    int arr[1000005];
    int cntno=0;
    vector<int>cannot;
    vector<int>idk;
    for(int i=0;i<n;i++){
        int l,t; cin>>l;
        
        info[i]=false;
        for(int j=0;j<l;j++){
            cin>>arr[j];
            if(j>=1)if(arr[j]>arr[j-1])info[i]=true;
        }
        if(info[i]==false){
            cntno++;
            cannot.pb(arr[0]);
            idk.pb(arr[l-1]);
        }
    }
    sort(idk.begin(),idk.end());
    long long ans=(n*n)-(cntno*cntno);
    //cout<<ans<<endl;
    for(int i=0;i<cntno;i++){
        int t=cannot[i];
        int l=0,r=cntno-1;
        //cout<<endl<<endl<<i<<" "<<t<<endl;
        while(l!=r){
            int mid=(l+r)/2;
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(idk[mid]<t)l=mid+1;
            else r=mid;
        }
        int zero=0;
        l=max(l-1,zero);
        while(l<cntno&&idk[l]<t)l++;
        //cout<<l<<endl;
        ans+=l;
    }
    cout<<ans<<endl;
    return 0;
}