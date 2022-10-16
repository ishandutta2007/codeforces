#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll ans = 0;
int field[11][100050];
int position[11][100500];
int n, m;

inline void search(int array, int left, int right){
    //cout << array << " " << left << " " << right << endl;
    if(array == m){
        ll delta = (ll)right - (ll)left;
        ans += delta * (delta + 1) / 2;
        //cout << left << " " << right << endl;
        return;
    }
    int Lindex = left;
    int Rindex = left + 1;
    for(; Rindex < right; Rindex++){
        //int Lvalue = field[array][Lindex];
        //int Rvalue = field[array][Rindex];
        if(position[array + 1][field[array][Rindex]] - position[array + 1][field[array][Lindex]] != Rindex - Lindex){
            search(array + 1, position[array + 1][field[array][Lindex]], position[array + 1][field[array][Lindex]] + Rindex - Lindex);
            Lindex = Rindex;
        }
    }
    //int Lvalue = field[array][Lindex];
    search(array + 1, position[array + 1][field[array][Lindex]], position[array + 1][field[array][Lindex]] + Rindex - Lindex);
    //search(array + 1, Lindex, Rindex);
    return;
}

int main() {
    //cout.precision(10);
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            //cin >> field[i][j];
            scanf("%d", &field[i][j]);
            position[i][field[i][j]] = j;
        }
    }
    /*for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout << position[i][j] << " ";
        }
        cout << endl;
    }*/
    search(1, 1, n + 1);
    //cout << ans << endl;
    printf("%lld\n", ans);
    return 0;
}