#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int a[300005];
int gde[300005];
int res[300005];

int bit[300005];

void addbit(int x, int val){
    while(x <= 300000){
        bit[x] += val;
        x += x & -x;
    }
}

int bitget(int x){
    int sol = 0;
    while(x){
        sol += bit[x];
        x -= x & -x;
    }
    return sol;
}

vector <int> ima[300005];
vector <pair <int, int>> vec[300005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, t;
    cin >> n >> t;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] = i-a[i];
    }
    int sve = 0;
    ordered_set <pair <int, int>> q;
    for(int i=1; i<=n; i++){
        if(a[i] < 0) continue;
        if(a[i] == 0){
            q.insert({-i, i});
            gde[i] = i;
            addbit(i, 1);
            sve++;
            ima[gde[i]].push_back(i);
            //cout << "insertujem " << -i << endl;
        }
        else{
            if(q.size() < a[i]) continue;
            auto c = q.find_by_order(a[i]-1);
            /*if(i == 10){
                for(auto c : q) cout << c << " b ";
                cout << endl;
            }*/
            gde[i] = -(c->first);
            q.insert({-gde[i], i});
            addbit(i, 1);
            sve++;
            ima[gde[i]].push_back(i);
            //cout << "insertujem" << -gde[i] << endl;
        }
    }

    /*for(int i=1; i<=n; i++){
        cout << gde[i] << " ";
    }
    cout << endl;*/
    for(int tt=1; tt<=t; tt++){
        int x, y;
        cin >> x >> y;
        vec[x].push_back({y, tt});
    }
    for(int i=0; i<=n; i++){
        if(i != 0){
            for(auto c : ima[i]){
                addbit(c, -1);
                sve--;
            }
        }
        sort(vec[i].begin(), vec[i].end());
        for(auto c : vec[i]){
            //cout << n-c.first << "a\n";
            //cout << bitget(5) << "b\n";
            //cout << bit[5] << "\n";
            res[c.second] = bitget(n-c.first);
        }
    }
    for(int i=1; i<=t; i++){
        cout << res[i] << "\n";
    }
    return 0;
}

/*
5 1
1 4 1 2 4
0 0
*/