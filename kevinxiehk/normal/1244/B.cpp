#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    int f=-1,l=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(f==-1)f=i;
            l=i;
        }
    }
    if(f==-1){cout<<n<<endl;return;}
    l=n-l-1;
    cout<<max(n,2*(n-min(f,l)))<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}