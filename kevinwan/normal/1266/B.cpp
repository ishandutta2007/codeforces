#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        ll x;
        scanf("%lld",&x);
        if(x<=14)printf("NO\n");
        else{
        x%=14;
        if(x>=1&&x<=6)printf("YES\n");
        else printf("NO\n");
        }
    }
}