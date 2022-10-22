#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=4e5+10;
int num[1<<24];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x=0;
        string s;
        cin>>s;
        for(char c:s)x|=1<<(c-'a');
        num[x]++;
    }
    for(int i=0;i<24;i++)for(int j=0;j<1<<24;j++)if((j>>i)&1)num[j]+=num[j-(1<<i)];
    ll ans=0;
    for(int i=0;i<1<<24;i++)ans^=1LL*(n-num[i])*(n-num[i]);
    printf("%lld",ans);
}