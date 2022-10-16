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
    int t=n/2;
    t++;
    cout<<t<<endl;
    for(int i=1;i<=t;i++)cout<<"1 "<<i<<endl;
    for(int i=2;i<=(n-t)+1;i++)cout<<i<<" "<<t<<endl;
	return 0;
}