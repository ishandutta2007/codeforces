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

int main () {
    scanf("%d", &n);
    int ile_zer = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a == 0) ile_zer++;
    }

    if (n == 1) {
        if (ile_zer == 0) printf("YES\n");
        else printf("NO\n");
    }
    else {
        if (ile_zer == 1) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}