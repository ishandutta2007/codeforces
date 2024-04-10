// Hydro submission #62d777f99ef728749e1de78d@1658288122076
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;

const int maxn=300010;

int p[maxn];

signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    int ans=0;

    priority_queue<int>am;
    //priority_queue<int>bm;

    for(int i=1;i<=n;i++){
        am.emplace(-p[i]);
        int mx=0,type;
        if(!am.empty()&&am.top()+p[i]>mx){
            mx=am.top()+p[i];
            type=1;
        }
        ans+=mx;
        if(type==1){
            am.pop();
            am.emplace(-p[i]);
        }
    }

    cout<<ans<<endl;
    return 0;
}