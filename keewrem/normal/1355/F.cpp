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
vll p;
vll ses[22]; ll pp[22];
bool isp[100000];
set<ll> dd; multiset<ll> sos;
queue<ll> qq;
int main(){
    for(int i = 2; i < 100000; i++){
        if(isp[i])continue;
        p.pb((ll)i);
        for(int j = i; j < 100000; j+= i)isp[j] = 1;
    }
    ll ind = 0, pr = 1LL;
    for(auto x: p){
        if(pr < 1000000000000000000/x){
            ses[ind].pb(x); pr*=x;
        }else{
            pp[ind] = pr;pr = 1LL; ind++;
        }
        if(ind == 22)break;
    }
    cin >> T;
    while(T--){
    dd.clear(); sos.clear(); while(!qq.empty())qq.pop();
    ll aaa,bbb,cc,ee;
    ll q; ll sesso = 1000000000;int tries = 0;
    for(int i = 0; i < 22 & tries < 22; i++){
        if(qq.size()> (21-tries)*2)break;
        while(qq.size()>1 && qq.front()*qq.front()<sesso && tries < 22){
            aaa = qq.front(); qq.pop(); bbb=qq.front();qq.pop();
            cc = aaa; ee = bbb;
            while(cc*aaa < 1000000001)cc*=aaa;
            while(bbb*ee < 1000000001)ee*=bbb;
            cout << "? " << cc*ee << endl;
            cout.flush();
            cin >> q;
            q/=aaa; q/=bbb;
            while(q%aaa == 0){
                sesso/=aaa; sos.insert(aaa); q/=aaa;
            }
            while(q%bbb == 0){
                sesso/=bbb; sos.insert(bbb); q/=bbb;
            }
            tries++;
        }
        if(ses[i][0]*ses[i][0]>sesso){break;}
        cout << "? " << pp[i] << endl;
        cout.flush();
        cin >> q;
        for(auto x: ses[i])if(q%x == 0){
            dd.insert(x); sos.insert(x); sesso/=x; qq.push(x);
        }
        tries++;
    }
    while(qq.size()>1 && qq.front()*qq.front()<sesso && tries < 22){
        aaa = qq.front(); qq.pop(); bbb=qq.front();qq.pop();
        cc = aaa; ee = bbb;
        while(cc*aaa < 1000000001)cc*=aaa;
        while(bbb*ee < 1000000001)ee*=bbb;
        cout << "? " << cc*ee << endl;
        cout.flush();
        cin >> q;
        q/=aaa; q/=bbb;
        while(q%aaa == 0){
            sesso/=aaa; sos.insert(aaa); q/=aaa;
        }
        while(q%bbb == 0){
            sesso/=bbb; sos.insert(bbb); q/=bbb;
        }
        tries++;
    }
    if(tries < 22 && (!qq.empty())){
        aaa = qq.front(); qq.pop();
        cc = aaa;
        while(cc*aaa < 1000000001)cc*=aaa;
        cout << "? " << cc << endl;
        cout.flush();
        cin >> q;
        q/=aaa;
        while(q%aaa == 0){
            sesso/=aaa; sos.insert(aaa); q/=aaa;
        }
    }
    ll rer = 1;
    for(auto x: dd)rer*=sos.count(x)+1;
    cout <<"! "<< 2*rer<<"\n"; cout.flush();
    }
    return 0;
}