#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <char, int>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    int sz = 1;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            sz++;
        }
        else{
            vec.push_back({s[i-1], sz});
            sz = 1;
        }
    }
    if(sz){
        vec.push_back({s[n-1], sz});
    }
    int res = 0;
    while(vec.size() > 1){
        int k = vec.size();
        for(int i=1; i<k-1; i++){
            vec[i].second -= 2;
        }
        vec[0].second--;
        vec[k-1].second--;
        vector <pair <char, int>> nvec;
        for(int i=0; i<k; i++){
            if(vec[i].second > 0){
                if(nvec.size() && nvec[nvec.size()-1].first == vec[i].first){
                    nvec[nvec.size()-1].second += vec[i].second;
                }
                else nvec.push_back({vec[i].first, vec[i].second});
            }
        }
        //for(auto c : nvec) cout << c.first << " " << c.second << endl;
        vec = nvec;
        res++;
    }
    cout << res;
    return 0;
}