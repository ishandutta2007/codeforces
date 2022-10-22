#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[100005];
vector <int> graf1[100005];

int n;

bool check(){
    for(int i=1; i<=n; i++){
        if(graf[i].size() != graf1[i].size()) return 0;
        sort(graf[i].begin(), graf[i].end());
        sort(graf1[i].begin(), graf1[i].end());
        for(int j=0; j<graf[i].size(); j++){
            if(graf[i][j] != graf1[i][j]) return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        if(a < b) graf[a].push_back(b);
        else graf[b].push_back(a);
    }
    for(int k=1; k<n; k++){
        if(n%k) continue;
        for(int i=1; i<=n; i++) graf1[i].clear();
        for(int i=1; i<=n; i++){
            for(auto c : graf[i]){
                int a = i+k;
                if(a > n) a -= n;
                int b = c+k;
                if(b > n) b -= n;
                if(a > b) swap(a, b);
                graf1[a].push_back(b);
            }
        }
        if(check()){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}