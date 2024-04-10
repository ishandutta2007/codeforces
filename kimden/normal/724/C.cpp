#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 2;

int n, m, k;
int x[MAXN], y[MAXN];
map<int, vector<int>> m_sum, m_diff;
vector<ll> ans;

int main()
{
    cin >> n >> m >> k;
    ans.resize(k, -1);
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i];
        m_sum[x[i] + y[i]].push_back(i);
        m_diff[x[i] - y[i]].push_back(i);
    }
    int curx = 0, cury = 0;
    int vx = 1, vy = 1;
    ll t = 0;
    int delta;
    while(1){
        if(vx == vy){
            for(auto ind: m_diff[curx - cury]){
                if(ans[ind] < 0){
                    ans[ind] = abs(curx - x[ind]) + t;
                }
            }
        } else {
            for(auto ind: m_sum[curx + cury]){
                if(ans[ind] < 0){
                    ans[ind] = abs(curx - x[ind]) + t;
                }
            }
        }
        switch((vx + 1) * 10 + (vy + 1)){
        case 22:
            delta = min(n - curx, m - cury);
            curx += delta;
            cury += delta;
            t += delta;
            break;
        case 20:
            delta = min(n - curx, cury);
            curx += delta;
            cury -= delta;
            t += delta;
            break;
        case 2:
            delta = min(curx, m - cury);
            curx -= delta;
            cury += delta;
            t += delta;
            break;
        case 0:
            delta = min(curx, cury);
            curx -= delta;
            cury -= delta;
            t += delta;
            break;
        }
        if(curx == n || curx == 0){
            vx *= -1;
            if(cury == m || cury == 0){
                break;
            }
        }
        if(cury == m || cury == 0){
            vy *= -1;
        }
    }
    for(auto k: ans){
        cout << k << endl;
    }
    return 0;
}