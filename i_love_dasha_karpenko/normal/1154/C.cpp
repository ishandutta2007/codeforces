
#include <bits/stdc++.h>

using namespace std;
#define DIM 150007
#define INF 10E16
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll a,b,c,a1,b1,c1,res=0;
void F(ll x){
    if (x==1 || x==4 || x==7)a--;
    else if (x==2 || x==6)b--;
    else c--;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);

    cin>>a>>b>>c;
    a1 = a; b1 = b; c1 = c;
    for (int  i =1;i<=7;i++){
        a = a1; b = b1; c = c1;
        ll r = 0;
        for (int j = i;j<=7 && a>=0 && b>=0 && c>=0;j++){
            F(j);
            r++;
            //cout<<a<<' '<<b<<' '<<c<<endl;
        }
        if (a<0 || b<0 || c<0){r--;res = max(res,r);continue;}
        ll am = a/3,bm = b/2,cm = c/2;
        ll d = min(am,min(bm,cm));
        a-=d*3; b-=d*2; c-=d*2;
        r+=d*7;
        //cout<<d<<" sdfdsf"<<endl;
        for (int j = 1;j<=7 && a>=0 && b>=0 && c>=0;j++){
            F(j);
            r++;
            //cout<<a<<' '<<b<<' '<<c<<endl;
        }
        if (a<0 || b<0 || c<0)r--;

        res = max(r,res);
        //cout<<r<<endl;
    }
    cout<<res<<endl;
}