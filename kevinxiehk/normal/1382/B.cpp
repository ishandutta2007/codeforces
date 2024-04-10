#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    int t;
    int id=99999999;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>1)id=min(id,i);
    }
    if(n==1){cout<<"First"<<endl;return;}
    if(id==99999999){
        if(n%2==1)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    else{
        if(id%2==1)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}