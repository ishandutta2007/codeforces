#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

pair <int, int> s[300005];
int ost[300005];
int t[300005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i].first;
        s[i].second = i;
    }
    for(int i=1; i<=n; i++){
        cin >> t[i];
    }
    sort(s+1, s+1+n);
    sort(t+1, t+1+n);
    stack <int> st;
    vector <tuple <int, int, int>> moves;
    for(int i=1; i<=n; i++){
        int idx = s[i].second;
        ost[idx] = t[i] - s[i].first;
        if(ost[idx] > 0) st.push(idx);
        else if(ost[idx] < 0){
            ost[idx] = -ost[idx];
            while(!st.empty()){
                int j = st.top();
                if(ost[j] >= ost[idx]){
                    ost[j] -= ost[idx];
                    moves.push_back({j, idx, ost[idx]});
                    ost[idx] = 0;
                    break;
                }
                if(ost[j]) moves.push_back({j, idx, ost[j]});
                ost[idx] -= ost[j];
                ost[j] = 0;
                st.pop();
            }
            if(st.empty() && ost[idx]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    while(!st.empty() && ost[st.top()] == 0) st.pop();
    if(!st.empty()){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << moves.size() << "\n";
    for(auto c : moves){
        cout << get<0>(c) << " " << get<1>(c) << " " << get<2>(c) << "\n";
    }
    return 0;
}