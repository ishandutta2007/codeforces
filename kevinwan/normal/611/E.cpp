#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=1e5+10;
multiset<int>s;
int v[3];
int a=0,b=0;
bool rem(int x,int lim){
    auto it=s.upper_bound(x);
    if(it==s.begin())return 0;
    if(*(--it)<=lim)return 0;
    if(*it<=v[2])a--;
    if(*it<=v[0]+v[1])b--;
    s.erase(it);
    return 1;
}
int ans=0;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    cin>>v[0]>>v[1]>>v[2];
    sort(v,v+3);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
        if(x>v[0]+v[1]+v[2]){printf("-1");return 0;}
    }
    while(rem(v[0]+v[1]+v[2],v[1]+v[2]))ans++;
    while(rem(v[1]+v[2],v[0]+v[2]))rem(v[0],0),ans++;
    while(rem(v[0]+v[2],max(v[0]+v[1],v[2])))rem(v[1],0),ans++;
    for(int x:s){
        if(x<=v[2])a++;
        if(x<=v[0]+v[1])b++;
    }
    int bes=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        bes=min(bes,ans+max((int)(s.size()+1)/2,abs(a-b)));
        ans++;
        rem(v[2],0),rem(v[1],0),rem(v[0],0);
    }
    printf("%d\n",bes);
}