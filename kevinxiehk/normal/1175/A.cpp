#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t;
	int a,b;
    int cnt=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        cnt=0;
            while(a>0){
                if(a%b==0){a/=b;cnt++;}
                else{cnt+=(a%b);a-=(a%b);}
            }
            cout<<cnt<<endl;
    }
	return 0;
}