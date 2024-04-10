#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n,k;
    int l1,l2,r1,r2;
    cin>>n>>k>>l1>>r1>>l2>>r2;
    if(l1>l2){
        swap(l1,l2);
        swap(r1,r2);
    }
    if(r2<=r1){
        k-=(r2-l2)*n;
        if(k<=0){cout<<"0"<<endl;return;}
        if(k<=(r1-l1-(r2-l2))*n){cout<<k<<endl;return;}
        else {
            k-=(r1-l1-(r2-l2))*n;
            cout<<k*2+(r1-l1-(r2-l2))*n<<endl;
            return;
        }
    }
    //cout<<"a"<<endl;
    if(l2<r1){
        k-=(r1-l2)*n;
        int t=r1-l2;
        r1-=t;
        r2-=t; 
    }
    if(k<=0){cout<<"0"<<endl;return;}
    //cout<<k<<endl;
    if(r1<=l2){
        int t=l2-r1;
        int tt=r2-l1;
        int ans=0;
        int aaa=k%tt;
        aaa=max(aaa,k-tt*n);
        int ahh=min(n,k/tt);
        //cout<<aaa<<" "<<ahh<<" "<<t<<" "<<tt<<endl;
        if(tt>=t){  
            ans+=ahh*(tt+t);
            if((aaa>=t||ahh==0)&&ahh!=n){
                ans+=aaa+t;
            }
            else ans+=aaa*2;
            cout<<ans<<endl;
            return;
        }
        else{
            ans+=t;
            if(k<=tt){cout<<k<<endl;return;}
            else k-=tt;
            cout<<k*2+tt<<endl;
            return;
        }
    }
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}