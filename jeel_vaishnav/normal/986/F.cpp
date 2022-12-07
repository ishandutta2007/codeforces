#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

const int MAX = 31622776;

unordered_map<ll, int> kMap;
unordered_map<ll, int> poss[50];
vector<vector<ll>> primeFactors;
vector<ll> primes;
int sieve[MAX];
ll p, q;

ll findGCD(ll a, ll b, ll n) {
    if(a == 0) {
        q = 1;
        p = 0LL;
        return b;
    }

    ll val = findGCD(b % a, a, n);
    ll temp = q;
    q = p;
    p = (temp - p * (b / a));

    return val;
}

void precomputeSieve() {
    for(int i = 0; i < MAX; ++i)
        sieve[i] = 0;
    for(int i = 2; i < MAX; ++i) {
        if(sieve[i] == 0) {
            primes.pb((ll)i);
            for(int j = i; j < MAX; j += i)
                sieve[j] = i;
        }
    }
}

vector<ll> primeFactorize(ll k) {
    vector<ll> ans;

    for(ll i : primes) {
        if(k % i == 0) {
            ans.pb(i);
            while(k % i == 0)
                k /= i;
        }
    }

    if(k > 1) {
        ans.pb(k);
    }

    return ans;
}

void createGraphAndFindPoss(vector<ll> curPrimeFactors, int kInd) {
    ll p1 = curPrimeFactors[0];

    set<pair<ll, ll>> pq;
    pq.insert({0, 0});
    poss[kInd][0] = 0;

    int vis[p1];
    for(int i = 0; i < p1; ++i)
        vis[i] = 0;
    while(!pq.empty()) {
        ll cost = pq.begin()->first;
        ll ind = pq.begin()->second;
        pq.erase(pq.begin());
        if(vis[ind] == 1)
            continue;
        poss[kInd][ind] = cost;
        vis[ind] = 1;
        for(ll i : curPrimeFactors) {
            if(i != p1) {
                pq.insert({cost + i, (ind + i) % p1});
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    precomputeSieve();

    int t;
    cin >> t;

    for(int x = 0; x < t; ++x) {

        ll n, k;
        cin >> n >> k;

        int kInd;
        vector<ll> curPrimeFactors;

        if(kMap.find(k) != kMap.end()) {
            kInd = kMap.find(k)->second;
            curPrimeFactors = primeFactors[kInd];
        }
        else {
            kInd = primeFactors.size();
            curPrimeFactors = primeFactorize(k);
            kMap[k] = kInd;
            primeFactors.pb(curPrimeFactors);
            if(curPrimeFactors.size() > 2) {
                createGraphAndFindPoss(curPrimeFactors, kInd);
            }
        }

        if(curPrimeFactors.size() == 0) 
            cout << "NO\n";
        else if(curPrimeFactors.size() == 1) {
            if(n % curPrimeFactors[0] == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if(curPrimeFactors.size() == 2) {
            //Extended Euclidean : p1 * a + p2 * b = n (a & b >= 0)
            ll gcd = findGCD(curPrimeFactors[0], curPrimeFactors[1], n);
            if(n % gcd != 0) 
                cout << "NO\n";
            else {
                ll val = curPrimeFactors[0] / gcd;
                q %= val;
                if(q < 0)
                    q += val;
                ll reqVal = q * ((n / gcd) % val) % val * curPrimeFactors[1];
                if(reqVal <= n)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
        else {
            if(poss[kInd].find(n % curPrimeFactors[0]) != poss[kInd].end() && poss[kInd][n % curPrimeFactors[0]] <= n)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}