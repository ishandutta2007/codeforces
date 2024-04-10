#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for(cin >> T; T; T -= 1){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> v;
        for(int i = 0; i < n; i += 1) if(s[i] == '1') v.push_back(i);
        if(v.size()){
            for(int i = 0; i <= v[0]; i += 1) if(v[0] - i <= m) s[i] = '1';
            for(int i = v.back(); i < n; i += 1) if(i - v.back() <= m) s[i] = '1';
            for(int i = 0; i + 1 < (int)v.size(); i += 1)
                for(int j = v[i]; j <= v[i + 1]; j += 1)
                    if((j - v[i] != v[i + 1] - j) and (j - v[i] <= m or v[i + 1] - j <= m)) s[j] = '1';
        }
        cout << s << "\n";
    }
    return 0;
}