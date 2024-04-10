#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll ukup=0;
ll br[10];
ll n;

map <vector <int>, int> chekt;

ll fakt[20];

void nadji(vector <int> vec){
    ll br0 = vec[0];
    ll bru=0;
    for(auto c : vec) bru += c;
    ll brperm;
    if(br0 == 0) brperm = fakt[bru];
    else brperm = (bru-br0)*fakt[bru-1];
    for(ll i=0; i<=9; i++){
        brperm /= fakt[vec[i]];
    }
    ukup += brperm;
}

void idi(vector <int> vec){
    if(chekt[vec]) return;
    chekt[vec] = 1;
    nadji(vec);
    vector <int> vec1;
    for(int i=0; i<=9; i++){
        vec1.push_back(vec[i]);
    }
    for(int i=0; i<=9; i++){
        if(vec1[i] < br[i]){
            vec1[i]++;
            idi(vec1);
            vec1[i]--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    n = s.size();
    fakt[0] = 1;
    for(int i=1; i<=19; i++){fakt[i] = fakt[i-1]*i;}
    for(int i=0; i<n; i++){
        br[s[i]-'0']++;
    }
    vector <int> vec1;
    for(int i=0; i<=9; i++){
        if(br[i] > 0) vec1.push_back(1);
        else vec1.push_back(0);
    }
    idi(vec1);
    cout << ukup;
    return 0;
}
//glupsam