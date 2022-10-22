#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;
int s[mn],a[mn],b[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",s+i);
    vector<int>o(n);
    iota(o.begin(),o.end(),0);
    sort(o.begin(),o.end(),[](int a,int b){return s[a]<s[b];});
    for(int i=0;i<n;i++){
        if(i<n/3)a[o[i]]=i,b[o[i]]=s[o[i]]-i;
        else if(i<2*n/3)b[o[i]]=i,a[o[i]]=s[o[i]]-i;
        else b[o[i]]=n-1-i,a[o[i]]=s[o[i]]-b[o[i]];
    }
    printf("YES\n");
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<n;i++)printf("%d ",b[i]);
}