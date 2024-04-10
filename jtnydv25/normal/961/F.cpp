#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const ll mod = 1e16 + 61;

ld inv = 1. / (ld)mod;

ll mul(ll a, ll b){
    ll x = (ll)((ld)a*(ld)b*inv +(ld)(1)/2.);
    ll ret = a*b-mod*x;
    if((ll)(ret) < 0)
        ret+=mod;
    return ret;
}


ll add(ll a, ll b){
	 a += b;
	 if(a >= mod) a -= mod;
	 return a;
}

ll sub(ll a, ll b){
	a -= b;
	if(a < 0) a += mod;
	return a;
}

const int N = 1e6 + 10;
const ll base = 97;
ll H[N];
char s[N];
ll pw[N];
int F[N];
inline ll getHash(int i, int j){
	return sub(H[j], mul(H[i - 1], pw[j - i + 1]));
}

int main(){
	int n;
	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], base);
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++){
		H[i] = add(mul(H[i - 1], base), s[i] - 'a' + 1);
	}

	int l, r;
    if(n & 1){
        l = r = (1 + n) >> 1;
        F[l] = -1;
    } else{
        l = n >> 1;
        r = l + 1;
        F[l] = (s[l] == s[r]) ? 1 : -1;
    }
    while(1){
        l--;
        r++;
        if(l <= 0) break;
        F[l] = -1;
        if(s[l] == s[r]) F[l] = 1;
        for(int k = min(r - l, F[l + 1] + 2); k >= 1; k -= 2){
            if(getHash(l, l + k - 1) == getHash(r - k + 1, r)){
            	F[l] = k;
            	break;
            }
        }
    }
    for(int k = 1; k <= n + 1 - k; k++) printf("%d ", F[k]);
}