#include <bits/stdc++.h>

using namespace std;

vector<long long int> rubles;
long long int least[10010];

int bsearch(int l, int r, long long int t, int s) {
    if(l+1==r) {
        if(least[r]<=t) return r;
        else return l;
    }
    if(l==r || s==15) return l;
    int mid = (l+r)/2;
    //cout << l << ' ' << r << ' ' << mid << '\n';
    if(least[mid]<=t) bsearch(mid, r, t, s+1);
    else bsearch(l, mid-1, t, s+1);
}

int main() {
    long long int numbers, sum=0;
    int coupons;
    cin >> numbers >> coupons;
    for(int a=1; a<2001; a++) {
        if(a%2) least[a] = (a*a-a)/2+1;
        else least[a] = (a*a)/2;
        //if(a < 20) cout << least[a] << " ";
    }
    for(int a=0; a<coupons; a++) {
        long long int d, p;
        cin >> d >> p;
        rubles.push_back(p);
    }
    sort(rubles.rbegin(), rubles.rend());
    int k = min((int)rubles.size(), bsearch(1, 2000, numbers, 0));
    for(int a=0; a<k; a++) {
        //cout << rubles[a] << ' ';
        sum+=rubles[a];
    }
    cout << sum;
}