#include <bits/stdc++.h>
using namespace std;

char ch[100000];
map <char, long> br;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, i;
    cin >> n;
    cin >> ch;
    for(i=0; i<n; i++){
        br[ch[i]]++;
    }
    if(br['B'] >= 1 && br['G'] >= 1 && br['R'] >= 1)cout << "BGR";
    else if(br['B'] >= 2 && br['G'] >=2)cout << "BGR";
    else if(br['B'] >= 2 && br['R'] >=2)cout << "BGR";
    else if(br['R'] >= 2 && br['G'] >=2)cout << "BGR";

    else if(br['B'] >= 2 && br['G'] >=1)cout << "GR";
    else if(br['B'] >= 2 && br['R'] >=1)cout << "GR";
    else if(br['G'] >= 2 && br['B'] >=1)cout << "BR";
    else if(br['G'] >= 2 && br['R'] >=1)cout << "BR";
    else if(br['R'] >= 2 && br['B'] >=1)cout << "BG";
    else if(br['R'] >= 2 && br['G'] >=1)cout << "BG";

    else if(br['B'] >= 1 && br['G'] >=1)cout << "R";
    else if(br['B'] >= 1 && br['R'] >=1)cout << "G";
    else if(br['R'] >= 1 && br['G'] >=1)cout << "B";
    else if(br['B'] >= 1)cout << "B";
    else if(br['G'] >= 1)cout << "G";
    else cout << "R";
    return 0;
}