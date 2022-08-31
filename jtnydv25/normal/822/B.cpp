#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m; string s, t;
    cin >> n >> m;
    cin >> s >> t;
    vector<int> vec; int ans = 1e8;
    for(int i = 0; i <= m - n; i++){
        int cnt = 0;
        vector<int> v;
        for(int j = i; j < i + n; j++){
            if(s[j - i] != t[j]) v.push_back(j - i + 1);
        }
        if(v.size() < ans){
            ans = v.size();
            vec = v;
        }
    }
    cout << ans << endl;
    for(int el : vec) cout << el << " ";
}