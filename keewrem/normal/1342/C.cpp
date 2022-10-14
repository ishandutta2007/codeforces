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
ll a,b,q,l,r;

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b>>q;
        bool tab[a*b];
        ll sum = 0LL;
        ll sus[a*b+1];
        sus[0] = 0;
        for(int i  = 0; i < a*b; i++){
            tab[i] = ((i%b)%a != (i%a)%b);
            if(tab[i])sus[i]++;
            sus[i+1] = sus[i];
            if(tab[i])sum++;
        }
        ll res;
        while(q--){
            res = 0;
            cin >> l >> r;
            if(l%(a*b)>0)res -= sus[l%(a*b)-1]; l -= l%(a*b);
            res += sus[r%(a*b)]; r-=r%(a*b);
            res += sum * ((r - l)/(a*b));
            cout << res << " \n"[q == 0];
        }
    }
    return 0;
}