#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int cur=1;
    int cn=0,cp=1;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a<0){
            cur=-cur;
        }
        if(cur>0){
            ++cp;
        }else{
            ++cn;
        }
    }
    cout<<1ll*cp*cn<<' '<<1ll*n*(n+1)/2-1ll*cp*cn<<endl;
    return 0;
}