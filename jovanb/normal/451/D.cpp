#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int br[2][2];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string str;
    ll ukup1=0, ukup2=0;
    cin >> str;
    int n = str.size();
    for(int i=0; i<n; i++){
        br[str[i]-'a'][i%2]++;
        ukup1 += br[str[i]-'a'][i%2];
        ukup2 += br[str[i]-'a'][1-(i%2)];
    }
    cout << ukup2 << " " << ukup1;
    return 0;
}