#include <iostream>
#include <algorithm>
using namespace std;

const int max_mn = 40;

bool map[max_mn][max_mn];
char cnt1[max_mn][max_mn][max_mn]; // [a][c][d] sum of (a, c) ~ (a, d)
int cnt2[max_mn][max_mn][max_mn][max_mn]; // [a][b][c][d] ??? of (a, c) ~ (b, d)
char cnt3[max_mn][max_mn][max_mn][max_mn]; // number of trailing zeros
int cnt4[max_mn][max_mn][max_mn][max_mn]; // [a][b][c][d] ??? of (a, c) ~ (b, d)

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            map[i][j] = c != '0';
        }
    for(int a = 0; a < n; a++) {
        cnt1[a][0][0] = map[a][0];
        for(int d = 1; d < m; d++)
            cnt1[a][0][d] = cnt1[a][0][d - 1] + map[a][d];
        for(int c = 1; c < m; c++)
            for(int d = c; d < m; d++)
                cnt1[a][c][d] = cnt1[a][0][d] - cnt1[a][0][c - 1];
    }
    for(int c = 0; c < m; c++) {
        for(int d = c; d < m; d++) {
            for(int a = 0; a < n; a++) {
                cnt2[a][a][c][d] = cnt3[a][a][c][d] = (cnt1[a][c][d] == 0);
                for(int b = a + 1; b < n; b++) {
                    if(cnt1[b][c][d] == 0) { // more 0, expand
                        cnt3[a][b][c][d] = cnt3[a][b - 1][c][d] + 1;
                        cnt2[a][b][c][d] = cnt2[a][b - 1][c][d] + cnt3[a][b][c][d];
                    } else { // no more 0, capolose
                        cnt3[a][b][c][d] = 0;
                        cnt2[a][b][c][d] = cnt2[a][b - 1][c][d];
                    }
                }
            }
        }
    }
    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            for(int c = 0; c < m; c++) {
                cnt4[a][b][c][c] = cnt2[a][b][c][c];
                for(int d = c + 1; d < m; d++)
                    cnt4[a][b][c][d] = cnt4[a][b][c][d - 1] + cnt2[a][b][c][d];
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> c >> b >> d;
        a--, b--, c--, d--;
        int sum = 0;
        for(int c1 = c; c1 <= d; c1++)
//            for(int d1 = c1; d1 <= d; d1++){
                sum += cnt4[a][b][c1][d];
//                cerr << a << " " << b << " " << c1 << " " << d1 << " " << cnt2[a][b][c1][d1] << endl;
//            }
        cout << sum << endl;
    }
    return 0;
}