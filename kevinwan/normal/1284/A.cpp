#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=5e1+10;
string a[mn],b[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        x--;
        cout<<a[x%n]<<b[x%m]<<"\n";
    }
}