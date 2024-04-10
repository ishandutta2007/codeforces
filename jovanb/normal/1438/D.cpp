#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int p[100005];

vector <pair <int, int>> pairs;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int sv = 0;
    queue <pair <int, int>> elems;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        sv ^= p[i];
    }
    if(n%2 == 0 && sv){
        cout << "NO\n";
        return 0;
    }
    if(n%2 == 0) n--;
    for(int i=1; i<=n; i++){
        elems.push({p[i], i});
    }
    queue <int> q1, q2, q3;
    while(elems.size() > 1){
        pair <int, int> a = elems.front();
        elems.pop();
        pair <int, int> b = elems.front();
        elems.pop();
        pair <int, int> c = elems.front();
        elems.pop();
        q1.push(a.second);
        q2.push(b.second);
        q3.push(c.second);
        pairs.push_back({a.second, b.second});
        elems.push({c.first, c.second});
    }
    int g = elems.front().second;
    for(auto c : pairs){
        q1.push(g);
        q2.push(c.first);
        q3.push(c.second);
    }
    cout << "YES\n";
    cout << q1.size() << "\n";
    while(!q1.empty()){
        cout << q1.front() << " " << q2.front() << " " << q3.front() << "\n";
        q1.pop();
        q2.pop();
        q3.pop();
    }
    return 0;
}