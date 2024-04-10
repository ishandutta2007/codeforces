#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int a,b,c,d,e,x,y;
    cin>>a>>b>>c>>d>>e;
    x=a/c;y=b/d;
    if(a%c!=0)x++;
    if(b%d!=0)y++;
    if(x+y>e)cout<<"-1"<<endl;
    else cout<<x<<" "<<y<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}