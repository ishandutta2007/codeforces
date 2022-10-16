#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t<=4)cout<<(4-t)<<endl;
        else if(t%2)cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}