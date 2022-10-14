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
const ll MOD = 1000000007;

ll fexp(ll b, ll e){
    ll res = 1;
    for(;e;e>>=1){
        if(e&1)res = (res*b)%MOD;
        b = (b*b)%MOD;
    }
    return res;
}

int T = 1;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi p(N);
        for(int i = 0; i < N; i++){cin >> p[i]; p[i]--;}
        vi k;
        for(int i = 0; i < N; i++){
            if(p[i] == -1)continue;
            int c=p[i];
            p[i] = -1;
            int cc = 1;
            int o;
            while(p[c]!=-1){
                cc++;
                o = c;
                c = p[c];
                p[o]=-1;
            }
            k.pb(cc);
        }
        int q;
        //cout << "v ";        for(auto x: k)cout << x <<" ";cout << "\n";
        if(N%3 == 2)q = 1;
        else if(N%3 == 1)q = 2;
        else q = 0;
        int ans = 0;
        if(q == 0){
            int c1 = 0,c2 = 0;
            for(auto& x: k){
                if(x%3 == 0)ans+=x/3-1;
                else ans += x/3;
                x%=3;
                if(x == 1)c1++;
                if(x == 2)c2++;
            }
            int tot = c2*2+c1;
            ans += tot/3 + abs(c2-tot/3);
        }
        if(q == 1){
            int c1 = 0,c2 = 0;
            for(auto& x: k){
                if(x%3 == 0)ans+=x/3-1;
                else ans += x/3;
                x%=3;
                if(x == 1)c1++;
                if(x == 2)c2++;
            }
            if(c2 > 0)c2--;
            else {c1-=2; ans++;}
            int tot = c2*2+c1;
            ans += tot/3 + abs(c2-tot/3);
        }
        if(q == 2){
            int t = ans;
            int c1 = 0,c2 = 0;
            vi v = k;
            for(auto& x: k){
                if(q == 2){
                    if(x%3 == 1 && x > 1){
                        x-=4; ans++; q = 0;
                    }
                }
                if(x%3 == 0)ans+=x/3-1;
                else ans += x/3;
                x%=3;
                if(x == 1)c1++;
                if(x == 2)c2++;
            }

            if(q == 2){
                if(c2*2+c1 == 1)ans++;
                else{
                    if(c2 > 0)c2--;
                    else {c1-=2; ans++;}
                    if(c2 > 0)c2--;
                    else {c1-=2; ans++;}
                }
            }
            int tot = c2*2+c1;
            ans += tot/3 + abs(c2-tot/3);
            k = v;
            q = 2;
            c1 = 0; c2 = 0;
            for(auto& x: k){
                if(x%3 == 0)t+=x/3-1;
                else t += x/3;
                x%=3;
                if(x == 1)c1++;
                if(x == 2)c2++;
            }

            if(q == 2){
                if(c2*2+c1 == 1)t++;
                else{
                    if(c2 > 0)c2--;
                    else {c1-=2; t++;}
                    if(c2 > 0)c2--;
                    else {c1-=2; t++;}
                }
            }
            tot = c2*2+c1;
            t += tot/3 + abs(c2-tot/3);
            q = 2;
            ans = min(ans,t);
        }
        cout << (fexp(2,q) * fexp(3,(N-2*q)/3))%MOD<<" "<< ans << "\n";
    }
    return 0;
}