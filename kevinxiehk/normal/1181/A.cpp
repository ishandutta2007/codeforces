#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,c;
    cin>>a>>b>>c;
    int tt=b-(b/c*c);
    int ttt=a-(a/c*c);
    a+=b;
    int ans=a/c;
    int t=a-(ans*c);
    if(tt==0)tt+=c;
    if(ttt==0)ttt+=c;
    if(tt+ttt<c){
        tt=c;
        ttt=c;
    }
    cout<<ans<<" "<<c-max(tt,ttt)<<endl;
	return 0;
}