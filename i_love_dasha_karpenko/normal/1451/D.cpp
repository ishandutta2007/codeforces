#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll d,k;
        cin>>d>>k;
        ll x = d-d%k,y = 0;
        y = sqrt(d*d-x*x);
        y-=y%k;
        ll turn = 0;
        while(x>=0){
            ll cnt = x/k+y/k;
            ll moves = 0;
            while(((x+k)*(x+k)+y*y<=d*d || cnt%2!=1-turn) && x>=0){
                ++moves;
                x-=k;
                y = sqrt(d*d-x*x);
                y-=y%k;
                cnt = x/k+y/k;
                if (cnt/2+cnt%2*(1-turn)<y/k)break;
            }
            if ((x+k)*(x+k)+y*y<=d*d  || cnt/2+cnt%2*(1-turn)<y/k || x<0){
                if (turn==1)cout<<"Ashish\n";
                else cout<<"Utkarsh\n";
                break;
            }
            turn^=1;
        }
    }
    return 0;
}