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
const int mn=300+10;
const ll mod=1e9+7;


string s[mn];
int a[3];
int hailveshy2(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    a[0]=a[1]=a[2]=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        a[(i+j)%3]+=(s[i][j]=='X');
    }
    int m=0;
    for(int i=1;i<3;i++)if(a[i]<a[m])m=i;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((i+j)%3==m){
        if(s[i][j]=='X')s[i][j]='O';
    }
    for(int i=0;i<n;i++)printf("%s\n",s[i].c_str());
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