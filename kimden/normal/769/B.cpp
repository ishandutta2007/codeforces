#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<pii> v;

bool comp(pii& p1, pii& p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}
vector<pii> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin() + 1, v.end(), &comp);
    auto it = v.begin();
    auto it2 = v.begin() + 1;
    while(it2 != it && it2 != v.end()){
        if(it->first > 0){
            ans.push_back({it->second, it2->second});
            it->first--;
            it2++;
        }else{
            it++;
        }
    }
    if(it2 != v.end()){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(auto p: ans){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
	return 0;
}