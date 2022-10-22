#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <string> vec;
unordered_map <string, ll> pos;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    ll maxi = 0;
    for(int i=0; i<n-1; i++){
        string s1 = "";
        s1 = s[i];
        s1 += s[i+1];
        pos[s1]++;
        maxi = max(maxi, pos[s1]);
        if(pos[s1] == 1) vec.push_back(s1);
    }
    for(auto str : vec){
        if(pos[str] == maxi){cout << str; return 0;}
    }
    return 0;
}