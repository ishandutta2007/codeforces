#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll N,T;


int main(){
    cin >> T;
    ll p,f,cw,cs,s,w;
    while(T--){
        cin >> p >> f >> cs >> cw >> s >> w;
        if(s > w){swap(s,w);swap(cs,cw);}
        ll ans = 0;ll tr;
        ll pl,fl,lcs,lcw;
        for(int i = 0; i <= cs && i*s <= p; i++){
            tr=i; fl=f; pl = p; lcw = cw; lcs = cs-i;
            pl-=i*s; tr+=min(lcw,pl/w); lcw-=min(lcw,pl/w);
            tr+=min(fl/s,lcs);
            fl-=min(fl/s,lcs)*s;
            tr+=min(lcw,fl/w);
            ans=max(tr,ans);

        }
        cout <<ans<<"\n";
    }
    return 0;
}