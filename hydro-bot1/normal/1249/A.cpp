// Hydro submission #61c7d4d348035a2390415565@1640755214092
//hydro
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,x;
bool b;
map<ll,bool>mapp;
int main(){
    scanf("%lld",&T);
    while(T--){
        b=0;mapp.clear();
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(mapp[x-1]||mapp[x+1])b=1;
            else mapp[x]=1;
        }
        if(b)putchar(50);
        else putchar(49);
        putchar(10);
    }
    return 0;
}