#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
    char c[5]{'a','e','i','o','u'};
    bool done=false;
    cin>>n;
    for(int i=5;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i<5)continue;
            for(int j=0;j<i;j++){
                for(int k=0;k<n/i;k++){
                    cout<<c[(k+j)%5];
                }
            }
            cout<<endl;
            done=1;
            break;
        }
    }
    if(!done)cout<<"-1"<<endl;
	return 0;
}