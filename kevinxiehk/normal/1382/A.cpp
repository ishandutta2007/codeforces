#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    bool cnt[1005][2];
    for(int i=0;i<=1000;i++){
        cnt[i][0]=false;
        cnt[i][1]=false;
    }
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        cnt[t][0]=true;
    }
    for(int i=0;i<m;i++){
        cin>>t;
        cnt[t][1]=true;
    }
    for(int i=0;i<=1000;i++){
        if(cnt[i][0]&&cnt[i][1]){
            cout<<"YES"<<endl<<"1 "<<i<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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