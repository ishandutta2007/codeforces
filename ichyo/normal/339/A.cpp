#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> v;
    REP(i, s.size()){
        if(s[i] >= '1' && s[i] <= '3'){
            v.push_back(s[i] - '1' + 1);
        }
    }
    sort(v.begin(), v.end());
    REP(i, v.size()){
        cout << v[i];
        if(i == v.size() - 1){
            cout << endl;
        }else{
            cout << "+";
        }
    }
    return 0;
}