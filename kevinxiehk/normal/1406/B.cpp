#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>neg,pos;
    bool hv0=false;
    int t;
    int ans=1;
    for(int i=0;i<n;i++){
        cin>>t;
        if(n<=5)ans*=t;
        if(t>0)pos.pb(t);
        else if(t<0)neg.pb(-t);
        else hv0=true;
    }
    if(n<=5){cout<<ans<<endl;return;}
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    if(pos.size()==0){
        if(hv0){cout<<"0"<<endl;return;}
        int ans=1;
        for(int i=0;i<5;i++)ans*=neg[i];
        cout<<ans*-1<<endl;
        return;
    }
    reverse(pos.begin(),pos.end());
    reverse(neg.begin(),neg.end());
    ans=pos[0];
    if(pos.size()+neg.size()<5){cout<<"0"<<endl;return;}
    if(pos.size()+neg.size()==5&&pos.size()%2==0){cout<<"0"<<endl;return;}
    int arr[5];
    for(int i=0;i<5;i++)arr[i]=0;
    if(pos.size()>=3)arr[0]=pos[1]*pos[2];
    if(pos.size()>=5)arr[1]=pos[3]*pos[4];
    if(neg.size()>=2)arr[2]=neg[1]*neg[0];
    if(neg.size()>=4)arr[3]=neg[3]*neg[2];
    sort(arr,arr+4);
    //cout<<pos.size()<<" "<<neg.size()<<endl;
    cout<<ans*arr[2]*arr[3]<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    cin>>t;
    
    while(t--)solve();
    return 0;
}