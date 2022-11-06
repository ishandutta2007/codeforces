#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int in[1010];
int main() {
    int n;
    ll s;
    scanf("%d %lld",&n,&s);
    ll tot=0;
    ll mi=1e9;
    for(int i=1 ;i<=n; i++){
        scanf("%d",&in[i]);
        tot+=in[i];
        mi=min(mi,(ll)in[i]);
    }
    if(tot<s){
        printf("-1\n");
        return 0;
    }
    int l=0,r=mi;
    ll m;
    while(l<=r){
        m=(l+r)/2;
        if(tot-m*n==s){
            r=m;
            break;
        }
        if(tot-m*n<s)r=m-1;
        else l=m+1;
    }
    printf("%d\n",r);

    return 0;
}