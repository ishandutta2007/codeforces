#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int getceil(int i, int j){ return (i - 1) / j + 1;}
const int MAX = 7000;
int main(){
    int t = 1, n;
    int Ha, Aa, Da, Hb, Ab, Db, H, A, D;
    cin >> Ha >> Aa >> Da >> Hb >> Ab >> Db >> H >> A >> D;
    // Ha -= max(0, Ab - Da)
    // Hb -= max(0, Aa - Db)
    int ans = 1000000007;
    for(int j = 0; j <= MAX; j++)
        for(int k = 0; k <= MAX; k++){
            int deltaA = max(0, Ab - Da - k);
            int deltaB = max(0, Aa - Db + j);
            if(deltaB == 0) continue;
            int iter = getceil(Hb, deltaB);
            // Ha + i - iter * deltaA > 0
            int i = max(0, iter * deltaA - Ha + 1);
            ans = min(ans, i * H + j * A + k * D);
        }
    cout << ans;
}