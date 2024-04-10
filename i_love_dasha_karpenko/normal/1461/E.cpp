#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2000+7;
const ll INF = 1E18;
void NO(){
    cout<<"No\n";
    exit(0);
}
void YES(){
    cout<<"Yes\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    if (k<l || k>r)NO();
    if (l+y>r){
        if (k-x*t<l)NO();
        else YES();
    }
    else{
        if (y>x){
            if (y%x==0){
                k-=l;
                r-=l;
                k%=x;
                if (k+y<=r)YES();
                else NO();
            }
            else{
                 k-=l;
                r-=l;
                ll ost = y%x;
                ll a = y/x;
                ll top = r-y;
                ll cnt = 0;
                t-=cnt;
                if (top-ost>=x)YES();
                else{

                    ll val = top-x;
                    set<ll> S;
                    cnt = k/x;

                    ll cur = (k%x);
                    while(1){
                        if (S.count(cur)){
                            cnt = INF;
                            break;
                        }
                        if (cur+y>r){
                            //cnt+=a;
                            break;
                        }
                        cnt+=(cur+y)/x;
                        S.insert(cur);
                        cur = (cur+y)%x;
                    }
                    //--cnt;
                    if (cnt>=t)YES();
                    else NO();
                }
            }
        }
        else{
            if (x==y && ((k+y)<=r || (k-x)>=l))YES();
            ll cnt = 0;
            if (k+y>r){
                ll lb = r-y;
                ll df = (k-lb);
                cnt = df/x;
                k-=x*cnt;
                if (k+y!=lb && k-x<l){
                    if (cnt>=t)YES();
                    else NO();
                }
                if (k+y!=lb){
                    k-=x;
                    ++cnt;
                }

            }
            if (cnt>=t)YES();
            ll dif = x-y;
            if (k/dif<(t-cnt))NO();
            if (k-dif*(t-cnt)<l)NO();
            else YES();
        }
    }
    return 0;
}