#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define N 1000
#define end asdfasdf
#define dec qwerqwer

pii inc[N], dec[N];
int n, st[N], end[N], delt, iut, dut;
int main() {
    scanf("%d", &n);
    fo(i,0,n) {
        scanf("%d %d", st+i, &delt);
        end[i] = st[i] + delt;
        st[i] = N*st[i] - i;
        end[i] = N*end[i] - i;
        if (delt >= 0) inc[iut++] = {st[i], end[i]};
        else dec[dut++] = {st[i], end[i]};
    }
    sort(inc, inc+iut); sort(dec, dec+dut);
    reverse(dec, dec+dut);

//    fo(i,0,iut) printf("%d %d\n", inc[i].first, inc[i].second);
//    puts("");
//    fo(i,0,dut) printf("%d %d\n", dec[i].first, dec[i].second);

    int ans = 0;
    fo(i,0,iut) fo(j,0,dut) if (inc[i].first < dec[j].first && inc[i].second > dec[j].second) { 
        ans++;
//        if (inc[i].second > dec[j].first || dec[j].second < inc[i].first) ans++;
    }
    fo(i,0,iut) fo(j,i+1,iut) {
        if (inc[i].second > inc[j].first) {
            ans++;
            if (inc[j].second > inc[i].second) ans++;
        }
    }
    fo(i,0,dut) fo(j,i+1,dut) {
        if (dec[i].second < dec[j].first) {
            ans++;
            if (dec[j].second < dec[i].second) ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}