#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define pb push_back

const int BUBEN = 11 * 1000 * 1000;

int d[BUBEN];
int lp[BUBEN];
 
int main() {
    // e-maxx - FTW
    vi pr;
    for (int i = 2; i < BUBEN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j = 0; j < sz(pr) && pr[j] <= lp[i] && i * pr[j] < BUBEN; ++j)
            lp[i * pr[j]] = pr[j];
    }
    d[1] = 1;
    for (int i = 2; i < BUBEN; ++i) {
        int p = lp[i];  
        int x = i, y = 1;
        while (x % p == 0) {
            x /= p; 
            if (x % p == 0) x /= p, y *= p;     
        }
        
        d[i] = d[x] * y;
        
        //cerr << i << " " << d[i] << "\n";
    }
    
    int a, n, b;
    cin >> a >> n >> b;
    b = a + n - 1;
    int64 res = 0;
    for (int i = a; i <= b; ++i)
        res += i / d[i] / d[i];
        
    cout << res << "\n";
        return 0;
}