#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int mi=min(min(a,b),c);
    int cnt=a%2+b%2+c%2;
    int cnt2=d%2;
    if(cnt==0)cout<<"Yes"<<endl;
    else if(cnt==1&&cnt2==0)cout<<"Yes"<<endl;
    else if(cnt==2&&cnt2==1&&mi>0)cout<<"Yes"<<endl;
    else if(cnt==3)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}