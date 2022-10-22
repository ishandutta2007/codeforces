#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,s1;
    int n;
    cin >> n;
    long long ans=0;
    for(int i=0;i<n;i++){
        char  k;
        cin >> k;
        if (k=='0' || k=='2' ||k=='4' ||k=='6' ||k=='8' ){
            ans+=(i+1);
        }
    }
    cout << ans;
    return 0;

}