#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=30)cout<<"NO"<<endl;
        else if(n==36)cout<<"YES"<<endl<<"6 10 15 5"<<endl;
        else if(n==40)cout<<"YES"<<endl<<"6 10 15 9"<<endl;
        else if(n==44)cout<<"YES"<<endl<<"6 10 15 13"<<endl;
        else cout<<"YES"<<endl<<"6 10 14 "<<n-30<<endl;
    }
    return 0;
}