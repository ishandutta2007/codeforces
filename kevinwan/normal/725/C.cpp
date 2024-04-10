#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

int lp[256];
int ans[26];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    string s;
    cin>>s;
    memset(lp,-1,sizeof(lp));
    int a,b;
    for(int i=0;i<27;i++){
        if(lp[s[i]]==-1)lp[s[i]]=i;
        else a=lp[s[i]],b=i;
    }
    //cerr<<a<<b;
    if(b==a+1){printf("Impossible");return 0;}
    int d=b-a;
    int of=(39-(d+1)/2-a)%26;
    cerr<<of;
    for(int i=0,j=of;i<27;i++){
        if(i==b)continue;
        ans[j]=s[i];
        j++;
        j%=26;
    }
    for(int i=0;i<13;i++)printf("%c",ans[i]);
    printf("\n");
    for(int i=25;i>=13;i--)printf("%c",ans[i]);
}