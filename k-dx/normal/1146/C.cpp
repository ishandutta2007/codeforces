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
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &n);
        int beg = 2, mid, end = n;
        printf("1 %d 1 ", n-1);
        for (int i = 2; i <= n; i++)
            printf("%d ", i);
        fflush(stdout);

        int max_from_1;
        scanf("%d", &max_from_1);

        while (beg != end) {
            mid = (beg + end) / 2;
            printf("1 %d 1 ", mid-beg+1);
            for (int i = beg; i <= mid; i++) 
                printf("%d ", i);
            fflush(stdout);

            int w;
            scanf("%d", &w);

            if (w < max_from_1) {
                beg = mid+1;
            }
            else {
                end = mid;
            }
        }

        printf("1 %d %d ", n-1, beg);
        for (int i = 1; i <= n; i++)
            if (i != beg)
                printf("%d ", i);
        fflush(stdout);

        int w;
        scanf("%d", &w);

        printf("-1 %d\n", w);
        fflush(stdout);
    }

    return 0;
}