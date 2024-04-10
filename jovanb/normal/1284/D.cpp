#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int e1[100005];
int s1[100005];
int e2[100005];
int s2[100005];

vector <pair <pair <int, int>, int>> v1;
multiset <pair <int, int>> intervals;
multiset <int> starts;
multiset <int> krajs;

void cant(){
    cout << "NO\n";
    exit(0);
}

void uradi(){
    sort(v1.begin(), v1.end());
    for(auto c : v1){
        pair <int, int> g = c.first;
        int i = c.second;
        if(g.second == 0){
            if(starts.size() && (*starts.rbegin() > e2[i] || *krajs.begin() < s2[i])) cant();
            starts.insert(s2[i]);
            krajs.insert(e2[i]);
        }
        else{
            starts.erase(starts.find(s2[i]));
            krajs.erase(krajs.find(e2[i]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s1[i] >> e1[i] >> s2[i] >> e2[i];
        v1.push_back({{s1[i], 0}, i});
        v1.push_back({{e1[i], 1}, i});
    }
    uradi();
    v1.clear();
    intervals.clear();
    for(int i=1; i<=n; i++){
        swap(s1[i], s2[i]);
        swap(e1[i], e2[i]);
        v1.push_back({{s1[i], 0}, i});
        v1.push_back({{e1[i], 1}, i});
    }
    uradi();
    cout << "YES\n";
    return 0;
}