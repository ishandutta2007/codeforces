#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define X first
#define Y second

int a[3][2];
int h[1005][1005];


void getpath(vector<ii> &ans, ii a, ii b) {
    if (a.X > b.X) swap(a, b);
    for(int i = a.X; i < b.X; i++) {
        if (!h[i][a.Y]) {
            h[i][a.Y] = 1;
            ans.push_back(ii(i, a.Y));
        }
    }
    int L = a.Y, R = b.Y;
    if (L > R) swap(L, R);
    for(int i = L; i <= R; i++) {
        if (!h[b.X][i]) {
            h[b.X][i] = 1;
            ans.push_back(ii(b.X, i));
        }
    }
}
int main() {
    for(int i = 0; i < 3; i++) 
        cin >> a[i][0] >> a[i][1];
    
    int ans = 10000000;
    for(int x = -1000; x <= 1000; x++) 
        for(int y = -1000; y <= 1000; y++) {
            int cur = 0;
            for(int i = 0; i < 3; i++) 
                cur += abs(x - a[i][0]) + abs(y - a[i][1]);
            ans = min(ans, cur);
        }

    for(int x = -1000; x <= 1000; x++) 
        for(int y = -1000; y <= 1000; y++) {
            int cur = 0;
            for(int i = 0; i < 3; i++) 
                cur += abs(x - a[i][0]) + abs(y - a[i][1]);
            if (cur == ans) {
                vector<ii> ansc;
                for(int i = 0; i < 3; i++) {
                    getpath(ansc, ii(x, y), ii(a[i][0], a[i][1]));
                }  
                cout << ansc.size() << '\n';
                for(auto i : ansc) cout << i.X << " " << i.Y << '\n';
                break;
            }
        }

}