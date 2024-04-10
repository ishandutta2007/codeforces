#include <bits/stdc++.h>
using namespace std;

#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;

const int N = 211111;
const int B = 61;
ll b[N];
int avail[B];
int bitpos[N];
vector<ll> nums_at[B];
bool solve() {
    int n;
    sf("%d", &n);
    fr(i,n) sf("%lld", &b[i]);
    sort(b, b + n);
    
    fr(k,B) avail[k] = 1;
    int i = n - 1;
    ffr(k,B) {
        while (i >= 0 && (b[i] & (1LL << k))) {
            // pf("bit %d: %lld\n", k, b[i]);
            if (!avail[k]) {
                return false;
            }
            avail[k]--;
            // pf("consume %d\n", k);
            fr(l,k) {
                if (b[i] & (1LL << l)) {
                    // pf("put %d\n", l);
                    avail[l]++;
                }
            }
            bitpos[i] = k;
            nums_at[k].push_back(b[i]);

            i--;
        }
    }
    assert(i == -1);
    fr(k,B) avail[k] = 1;
    vector<ll> ans;
    ll prev = 0;
    ll lahat = 0;
    // pf("\n");
    fr(i,n) {
        // pf("at %d\n", i);
        bool ok = false;
        fr(k,B) {
            if (avail[k] && !nums_at[k].empty()) {
                ll num = nums_at[k].back(); nums_at[k].pop_back();
                // pf("found %d: %lld\n", k, num);
                avail[k] = 0;
                fr(j,k) {
                    if (num & (1LL << j)) {
                        // pf("putting %d\n", j);
                        avail[j] = 1;
                    }
                }
                ans.push_back(num);
                lahat ^= num;
                assert(prev < lahat);
                prev = lahat;
                ok = true;
                break;
            }
        }
        assert(ok);
    }
    puts("Yes");
    fr(i,ans.size()) {
        pf("%lld%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return true;
}
int main() {
    if (!solve()) {
        puts("No");
    }
}