#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=2e5+10;
const ll mod=1e9+7;

int hailveshy(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    printf("%s\n",s.c_str());
    return 0;
}
int a[mn],b[mn];
int hailveshy2(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    for(int i=0;i<n;i++){
        bool ded=0;
        for(int j=0;j<n;j++)if(abs(a[i]-a[j])+abs(b[i]-b[j])>k)ded=1;
        if(ded)continue;
        printf("1\n");
        return 0;
    }
    printf("-1\n");
    return 0;
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        hailveshy2();
    }
}