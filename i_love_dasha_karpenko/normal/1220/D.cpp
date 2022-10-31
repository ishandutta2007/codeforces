#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define MODULO 998244353
const ll MAXN = ll(10E8);
const ll INF = 10E16;
const ll masksz = 1048576;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
ll n,A[DIM],bits[65];
int main() {
	schnell;
	cin>>n;
	forn(i,n)cin>>A[i];
	ll np = 0;
	forn(i,n){
	    if (A[i]%2==1)np++;
	    else{
            ll c = 0;
            ll x= A[i];
            while(x>0){
                if (x&1){
                    break;
                }
                x/=2;
                c++;
            }
            bits[c]++;
	    }
	}

    ll bd = 0,bit;
    for(ll i = 64;i>=0;i--){
        if (bd<bits[i]){
            bd = bits[i];
            bit = i;
        }
    }
    ll g = n-np-bd;
    bd = g;
    if (bd+np>n-np){
        cout<<n-np<<endl;
        forn(i,n)if(A[i]%2==0)cout<<A[i]<<' ';
    }
    else{
        cout<<bd+np<<endl;
        forn(i,n){
            if (A[i]%2==1)cout<<A[i]<<' ';
            if (A[i]%2==0){
                ll k = A[i];
                ll c = 0;
                while(k>0){
                    if (k&1)break;
                    k/=2;
                    c++;
                }
                if (c!=bit)cout<<A[i]<<' ';
            }
        }
    }
	return 0;
}