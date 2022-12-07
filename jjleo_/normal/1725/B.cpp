#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
ll p[N];
int main(){
    int n;
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    sort(p+1,p+1+n);
    int l=1;
    int ans=0;
    for(int i=n;i>=1;i--){
        if(l>i)break;
        ll ini=p[i];
        while(ini<=d&&l<i){
            ini+=p[i];
            l++;
        }
        if(ini>d){
            ans++;
        }
    }
    cout<<ans<<endl;
}