#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
    return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m,a,b,c,d,p;
        cin >> n >> m >> a >> b >> c >> d >> p;
        int lcm = (2*(n-1)*2*(m-1))/__gcd(2*(n-1),2*(m-1));
        vector<int>sy;
        vector<int>sx;
        int curx = a; int cury = b;
        int dx = 1; int dy = 1;
        for(int i = 0; i<(2*m-2); i++){
            if(cury==d){
                sy.push_back(i);
            }
            if(cury==m&&dy==1)dy*=-1;
            if(cury==1&&dy==-1)dy*=-1;
            cury+=dy;
        }
        for(int i = 0; i<(2*n-2); i++){
            if(curx==c){
                sx.push_back(i);
            }
            if(curx==n&&dx==1)dx*=-1;
            if(curx==1&&dx==-1)dx*=-1;
            curx+=dx;
        }
       // cout << lcm << "\n";
        set<int>s;
        for(int nxt: sy){
            int cur = nxt;
            while(cur<lcm){
                s.insert(cur);
                cur+=(2*m-2);
            }
        }
        for(int nxt: sx){
            int cur = nxt;
            while(cur<lcm){
                s.insert(cur);
                cur+=(2*n-2);
            }
        }
        int prob = p*modpow(100,mod-2)%mod;
        int inv = (100-p)*modpow(100,mod-2)%mod;
        vector<int>powers(s.size()+5);
        powers[0] = 1;
        for(int i = 1; i<powers.size(); i++){
            powers[i] = powers[i-1]*inv%mod;
        }
        vector<int>vals;
        int cnt = 0;
        for(int nxt: s){
            //cout << nxt << " ";
            vals.push_back(nxt);
        }
        //c/out << "\n";
        //cout << "\n";
        int cycle = powers[(int)vals.size()];
        for(int i = 0; i<vals.size(); i++){
            cnt+=vals[i]*powers[i]%mod; cnt%=mod;
        }
        int extra = lcm;
        extra*=cycle; extra%=mod; 
        int den = 1+mod-inv;
        den+=mod; den%=mod;
        extra*=modpow(den,mod-2); extra%=mod;
        cnt+=extra;
        cnt%=mod;
        //cout << cnt << "\n";
        int v = (1-cycle+mod)%mod;
        v+=2*mod; v%=mod;
        cnt*=prob;cnt%=mod;
        cnt*=modpow(v,mod-2); cnt%=mod;

        cout << cnt << "\n";
    }
    return 0;
}