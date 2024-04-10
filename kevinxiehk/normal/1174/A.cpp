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
    int arr[n*2+5];
    for(int i=0;i<2*n;i++)cin>>arr[i];
    sort(arr,arr+(2*n));
    if(arr[0]==arr[2*n-1]){
        cout<<"-1"<<endl;
        return 0;
    }
    else {
        for(int i=0;i<2*n;i++){
            cout<<arr[i];
            if(i!=n*2-1)cout<<" ";
            else cout<<endl;
        }
    }
	return 0;
}