#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int c=0,d=0;
        for(int i=0;i<a;i++){
            int x;
            scanf("%d",&x);
            c=max(c,x);
        }
        for(int i=0;i<b;i++){
            int x;
            scanf("%d",&x);
            d=max(d,x);
        }
        if(c>d)printf("YES\n");
        else printf("NO\n");
    }
}