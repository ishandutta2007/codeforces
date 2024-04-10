#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> br;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int ima=0;
    int ukup=0;
    for(int i=0; i<int(s.size()); i++) br[s[i]-'a']++;
    for(int i=0; i<26; i++){
        if(br[i] > 1) ima++;
        if(br[i] > 0) ukup++;
    }
    if(ukup < 2){cout << "No"; return 0;}
    if(ukup > 4){cout << "No"; return 0;}
    if(ukup == 4){cout << "Yes"; return 0;}
    if(ukup == 2){
        if(ima == 2) cout << "Yes";
        else cout << "No";
        return 0;
    }
    if(ima){cout << "Yes"; return 0;}
    cout << "No";
    return 0;
}