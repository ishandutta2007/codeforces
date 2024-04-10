#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <pair <int, int>> vec;
stack <pair <int, int>> stek;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int w;
    for(int i=1; i<=n; i++){
        cin >> w;
        vec.push_back({w, i});
    }
    string s;
    cin >> s;
    sort(vec.begin(), vec.end());
    int tren=0;
    for(auto c : s){
        if(c == '0'){
            pair <int, int> x = vec[tren];
            tren++;
            cout << x.second << " ";
            stek.push({-x.first, x.second});
        }
        else{
            pair <int, int> y = stek.top();
            stek.pop();
            cout << y.second << " ";
        }
    }
    return 0;
}