#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=200+10;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int g0=0,g1=0,g2=0,v;
        int num=0;
        for(char c:s){
            if(c=='.')num++;
            else{
                if(num>=2*b)g2++,v=num;
                else if(num>=a)g1++;
                else if(num>=b)g0++;
                num=0;
            }
        }
        if(num>=2*b)g2++,v=num;
        else if(num>=a)g1++;
        else if(num>=b)g0++;
        if(g2>1||g0){
            printf("NO\n");
            continue;
        }
        if(!g2){
            if(g1&1)printf("YES\n");
            else printf("NO\n");
            continue;
        }
        int am=(g1&1);
        if(am){
            if(2*b<=a)printf("NO\n");
            else if(2*a<=v&&v<=3*b+a-2)printf("YES\n");
            else printf("NO\n");
        }
        else{
            if(a<=v&&v<=a+2*b-2)printf("YES\n");
            else if(2*b<=a)printf("NO\n");
            else if(3*a<=v&&v<=4*b+a-2)printf("YES\n");
            else printf("NO\n");
        }
    }
}