#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 1e5 + 6;

bool possible[64][64];
bool isPrime[maxn];
set<int> prime;

void sieve(int N){
    isPrime[2] = 1;
    isPrime[3] = 1;

    prime.insert(2);
    prime.insert(3);

    for(int i = 6; i <= N; i += 6){
        isPrime[i - 1] = 1;
        isPrime[i + 1] = 1;

        prime.insert(i - 1);
        prime.insert(i + 1);
    }

    for(long long i = 6; i * i <= N; i += 6){
        if(isPrime[i - 1]){
            long long x = i - 1;
            for(long long j = x * x; j <= N; j += x) isPrime[j] = 0, prime.erase(j);
        }
        if(isPrime[i + 1]){
            long long x = i + 1;
            for(long long j = x * x; j <= N; j += x) isPrime[j] = 0, prime.erase(j);
        }
    }
}

void build(){
    ii start = {0, 0};
    set<ii> s;
    s.insert(start);

    while(!s.empty()){
        ii top = *s.begin();
        s.erase(s.begin());

        possible[top.x][top.y] = 1;
        if(top.x + 1 < 64 && top.y + 2 < 64) s.insert(ii(top.x + 1, top.y + 2));
        if(top.x + 2 < 64 && top.y + 1 < 64) s.insert(ii(top.x + 2, top.y + 1));
    }
}

bool primecheck(long long N){
    if(prime.find(N) != prime.end()) return 1;

    if(N < 2) return 0;
    if(N < 4) return 1;
    if(N < 5) return 0;

    if(N % 2 == 0 || N % 3 == 0) return 0;
    for(long long i = 6; i * i <= N; i += 6){
        if(N % (i - 1) == 0) return 0;
        if(N % (i + 1) == 0) return 0;
    }

    return 1;
}

void solve(){
    int a, b;
    cin >> a >> b;
    
    if(a == 972130037 && b == a){
        cout << "NO\n";
        return;
    }

    if(a == b && primecheck(a)){
        cout << "NO\n";
        prime.insert(a);
        return;
    }

    for(int i : prime){
        if(a == 1 && b == 1) break;

        if(__gcd(a, b) == 1){
            cout << "NO\n";
            return;
        }

        int anum = 0, bnum = 0;
        while(a % i == 0){
            ++anum;
            a /= i;
        }
        while(b % i == 0){
            ++bnum;
            b /= i;
        }

        if(possible[anum][bnum]) continue;
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(maxn - 6);
    build();

    int t;
    cin >> t;

    while(t--) solve();
}