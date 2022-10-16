#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
    cin>>n;
    int arr[n];
    bool isodd=false,allsame=true;
    bool now=false;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        now=(arr[i]%2==1);
        if(i!=0){
            if(isodd!=now)allsame=false;
        }
        isodd=now;
    }
    if(!allsame)sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1)cout<<" ";
        else cout<<endl;
    }
	return 0;
}