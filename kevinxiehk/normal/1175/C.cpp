#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    int n,k;
    int arr[1000000];
    for(int i=0;i<t;i++){
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>arr[i];
        int min=10000000000;
        int minoof;
        for(int i=0;i+k<n;i++){
            int t=arr[i+k]-arr[i];
            if(t<min){
                min=t;
                minoof=arr[i]+(t/2);
            }
        }
        cout<<minoof<<endl;
    }
	return 0;
}