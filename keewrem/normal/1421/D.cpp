#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;
ll c[7];
int main(){
    cin >> T;
    while(T--){
        ll x,y;
        cin >> x >> y;
        for(int i = 1; i < 7; i++)cin >> c[i];
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < 6; i++){
                if(i==0)c[1]=min(c[6]+c[2],c[1]);
                else if(i==5)c[6]=min(c[1]+c[5],c[6]);
                else c[i+1]=min(c[i]+c[i+2],c[i+1]);
            }
        }
        ll px=0,py=0,cst=0;
        ll ans = 4000000000000000000;
        if(y < 0){
            cst-=y*c[4];
            if(x-y>0)cst+=c[6]*(x-y);
            else cst-=c[3]*(x-y);
            ans=min(ans,cst);
        }else{
            cst+=y*c[1];
            if(y-x>0)cst+=c[3]*(y-x);
            else cst-=c[6]*(y-x);
            ans=min(ans,cst);
        }
        if(x < 0){
            cst = 0;
            cst-=x*c[4];
            if(x < y)cst+=(y-x)*c[2];
            else cst+=(x-y)*c[5];
            ans=min(ans,cst);
            cst=0;
            cst-=x*c[3];
            if(y>0)cst+=y*c[2];
            else cst-=y*c[5];
            ans=min(ans,cst);
        }else{
            cst=x*c[6];
            if(y > 0)cst+=c[2]*y;
            else cst-=c[5]*y;
            ans=min(ans,cst);
            cst=0;
            cst+=c[1]*x;
            y-=x;
            if(y > 0)cst+=c[2]*y;
            else cst-=c[5]*y;
            ans=min(ans,cst);
        }
        cout << ans << "\n";
    }
    return 0;
}