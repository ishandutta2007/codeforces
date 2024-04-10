#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    map<char, char> mp1, mp2;
    mp1['q'] = 'w';
    mp1['w'] = 'e';
    mp1['e'] = 'r';
    mp1['r'] = 't';
    mp1['t'] = 'y';
    mp1['y'] = 'u';
    mp1['u'] = 'i';
    mp1['i'] = 'o';
    mp1['o'] = 'p';
    mp1['a'] = 's';
    mp1['s'] = 'd';
    mp1['d'] = 'f';
    mp1['f'] = 'g';
    mp1['g'] = 'h';
    mp1['h'] = 'j';
    mp1['j'] = 'k';
    mp1['k'] = 'l';
    mp1['l'] = ';';
    mp1['z'] = 'x';
    mp1['x'] = 'c';
    mp1['c'] = 'v';
    mp1['v'] = 'b';
    mp1['b'] = 'n';
    mp1['n'] = 'm';
    mp1['m'] = ',';
    mp1[','] = '.';
    mp1['.'] = '/';
    for(auto u: mp1){
        mp2[u.second] = u.first;
    }
    string s, t;
    cin >> s;
    cin >> t;
    if(s == "L"){
        for(int i = 0; i < t.size(); ++i){
            t[i] = mp1[t[i]];
        }
    }else{
        for(int i = 0; i < t.size(); ++i){
            t[i] = mp2[t[i]];
        }
    }
    cout << t << endl;

}