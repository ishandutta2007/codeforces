#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

vector< pair<int, int> > path = {{6,3},{7,1},{5,0},{3,1},{1,0},{0,2},{2,1},{0,0},{1,2},{2,0},
                                 {0,1},{1,3},{0,5},{1,7},{3,6},{5,7},{7,6},{6,4},{7,2},{6,0},
                                 {4,1},{6,2},{7,0},{5,1},{3,0},{1,1},{0,3},{2,2},{4,3},{2,4},
                                 {1,6},{0,4},{2,3},{1,5},{0,7},{2,6},{4,7},{6,6},{7,4},{5,5},
                                 {6,7},{7,5},{5,6},{7,7},{6,5},{7,3},{6,1},{4,0},{3,2},{5,3},
                                 {4,5},{3,7},{2,5},{4,4},{5,2},{3,3},{1,4},{0,6},{2,7},{3,5},
                                 {5,4},{4,2},{3,4},{4,6}};

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int k;
    cin >> k;
    vector< pair<int, int> > a(k);
    for(int i = 0; i < k; i++) {

        char c, d;
        cin >> c >> d;
        a[i] = {c - 'a', d - '1'};
        //a[i] = path[64 -1 - k];
    }

    map< pair<int, int>, int > back;
    for(int i = 0; i < 64; i++)
        back[path[i]] = i;

    vector<int> gd(64);
    vector<int> hv(64);

    vector< pair< pair<int, int>, pair<int, int> > > ans, rans;

    for(int i = 0; i < k; i++)
        hv[back[a[i]]] = 1;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i  + j * 8 < k)
                gd[back[{i, j}]] = 1;
        }
    }

    for(int i = 0; i < 64; i++){
        if(hv[i]){
            while(i && !hv[i - 1]){
                ans.push_back({path[i], path[i - 1]});
                hv[i - 1] = 1;
                hv[i] = 0;
                i--;
            }
        }
    }
    for(int i = 0; i < 64; i++){
        if(gd[i]){
            while(i && !gd[i - 1]){
                rans.push_back({path[i - 1], path[i]});
                gd[i - 1] = 1;
                gd[i] = 0;
                i--;
            }
        }
    }

    while(!rans.empty()){
        ans.push_back(rans.back());
        rans.pop_back();
    }
    if(ans.size() < 1500) {
        cout << ans.size() << '\n';
        for (auto &x : ans) {
            cout << char(x.first.first + 'a') << x.first.second + 1 << '-';
            cout << char(x.second.first + 'a') << x.second.second + 1 << '\n';
        }
    }
    else {
        assert(false);
    }







    return 0;
}