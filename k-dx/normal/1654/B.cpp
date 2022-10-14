#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 0;

int n;
string s;
bool vis[1000];

// sprawdzamy czy substr [l, x]
// wystepuje w substr [l, r)
// bool myfind (int l, int r, int x) {
//     int wsk = l;
//     for (int i = l+1; i < r; i++) {
//         if (s[i] == s[wsk]) {
//             if (wsk == x) {
//                 return true;
//             }
//             wsk++;
//         }
//         else {
//             wsk = l;
//         }
//     }
//     return false;
// }

// int find_x (int l, int r) {
//     int beg = l, mid, end = r;
//     while (beg + 1 != end) {
//         mid = (beg + end) / 2;
//         if (myfind(l, r, mid)) {
//             beg = mid;
//         }
//         else {
//             end = mid;
//         }
//     }
//     return ;
// }

int main () {
    BOOST;

    int ttt;
    cin >> ttt;
    while (ttt--) {
        fill(vis, vis+990, false);
        cin >> s;
        
        int end = n-1;
        for (int i = (int)s.size()-1; i >= 0; i--) {
            if (!vis[(int)s[i]]) {
                end = i;
                vis[(int)s[i]] = true;
            }
        }
        for (int i = end; i < s.size(); i++) {
            cout << s[i];
        }
        cout << "\n";
        // while (beg + 1 != end) {
        //     mid = (beg + end) / 2;
        //     if (sprawdz(mid)) {
        //         end = mid;
        //     }
        //     else {
        //         beg = mid;
        //     }
        // }
        // int l = 0, r = s.size();
        // int x = -1;
        // while (x = find_x(l, r) != 0) {
        //     logg(x);
        //     l += x;
        // }


    
    }
    return 0;
}