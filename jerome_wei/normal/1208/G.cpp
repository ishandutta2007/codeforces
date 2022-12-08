#include <bits/stdc++.h>
using namespace std;
int phi[1000006];
void process_phis(int n){
    iota(phi,phi+n+1,0);
    for(int i = 2 ; i<=n;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(int j=2*i;j<=n;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<3<<endl;
        return 0;
    }
    process_phis(n);
	k+=2;
    sort(phi+1,phi+n+1);
    cout<<accumulate(phi+1,phi+k+1,0LL)<<endl;
    return 0;
}