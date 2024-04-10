#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);

int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>gps;
        int ln=-2;
        int ans=0,numw=0;
        for(int i=0;i<n;i++){
            if(s[i]=='W'){
                numw++;
                if(ln!=-2&&ln!=i-1)gps.push_back(i-ln-1);
                if(ln!=-2&&ln==i-1)ans+=2;
                else ans++;
                ln=i;
            }
        }
        k=min(k,n-numw);
        ans+=2*k;
        if(k&&!numw)ans--;
        sort(gps.begin(),gps.end());
        for(int x:gps){
            if(k>=x)ans++,k-=x;
        }
        printf("%d\n",ans);
    }
}