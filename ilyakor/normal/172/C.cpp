#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
 
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define pb push_back
 
int main() {
        int n, m;
        cin >> n >> m;
        vi vx(n);
        
        vi res(n);
        
        int T = 0;
        for (int i = 0; i < n; ++i) {
            int t;
            scanf("%d%d", &t, &vx[i]);
            if ((i + 1) % m == 0 || i == n - 1) {
                T = max(T, t);
                
//              cerr << T << "\n";
                    
                    
                int cur = i - i % m;
                vector<ii> v;
                for (int j = cur; j <= i; ++j)
                    v.push_back(make_pair(vx[j], j));
                
                sort(all(v));
                int p = 0;
                int x = 0;
                while (p < sz(v)) {
                    T += v[p].first - x;;
                    x = v[p].first;
                    
                    int q = p;
                    while (q < sz(v) && v[q].first == v[p].first) {
                        res[v[q].second] = T;
                        ++q;
                    }
                    
                    int dt = 1 + (q - p) / 2;
                    T += dt;
                    
                    p = q;
                }
                
                T += x;
            }
        }
        
        for (int i = 0; i < sz(res); ++i)
            printf("%d ", res[i]);
        printf("\n");
        return 0;
}