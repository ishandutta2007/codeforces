#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;

void go(int x, int y, int * x1, int * y1, int dp) {
    *x1 = x;
    *y1 = y;
    if (dp == 0)
        (*x1)++;
    if (dp == 1)
        (*y1)++;
    if (dp == 2)
        (*x1)--;
    if (dp == 3)
        (*y1)--;
    return;
}

bool check(int x1, int y1, int m, int l) {
    return ((x1 >= 0) && (x1 < l) && (y1 >= 0) && (y1 < m));
}


int main() {
    int m, n;
    string s;
    cin >> m >> n;
    vector<vector<int> > data(m);
    for (int i = 0; i < m; ++i) {
        cin >> s;
        data[i].resize(s.size());
        for (int j = 0; j < s.size(); ++j)
            data[i][j] = (s[j] - '0');
    }
    int l = s.size();
    vector<vector<vector<int> > > move(m, vector<vector<int> > (s.size(), vector<int> (8, -1)));
    int cp = 0;
    int dp = 0;
    int x = 0;
    int y = 0;
    int mov = 0;
    int per = 0;
    while (mov < n) {
        //move[x][y][bp + 2 * dp] = m;
        int x1, y1;
        
        while (mov < n) {
            while (true) {
                go(x, y, &x1, &y1, dp);
                if ((check(x1, y1, m, l)) && (data[y][x] == data[y1][x1])) {
                    if ((move[y][x][cp + 2 * dp] != mov) && (move[y][x][cp + 2 * dp] != -1)) {
                        per = mov - move[y][x][cp + 2 * dp];
                        while (n - per > mov)
                            n -= per;
                    }
                    else
                        move[y][x][cp + 2 * dp] = mov;
                    x = x1;
                    y = y1;
                }
                else {
                    if ((move[y][x][cp + 2 * dp] != mov) && (move[y][x][cp + 2 * dp] != -1)) {
                        per = mov - move[y][x][cp + 2 * dp];
                        while (n - per > mov)
                            n -= per;
                    }
                    else
                        move[y][x][cp + 2 * dp] = mov;

                    break;
                }
            }
            while (true) {
                int cdp = (dp + 3 + 2 * cp) % 4;
                go(x, y, &x1, &y1, cdp);
                if ((check(x1, y1, m, l)) && (data[y][x] == data[y1][x1])) {
                    if ((move[y][x][cp + 2 * dp] != mov) && (move[y][x][cp + 2 * dp] != -1)) {
                        per = mov - move[y][x][cp + 2 * dp];
                        while (n - per > mov)
                            n -= per;
                    }
                    else
                        move[y][x][cp + 2 * dp] = mov;
                    x = x1;
                    y = y1;
                }
                else {
                    if ((move[y][x][cp + 2 * dp] != mov) && (move[y][x][cp + 2 * dp] != -1)) {
                        per = mov - move[y][x][cp + 2 * dp];
                        while (n - per > mov)
                            n -= per;
                    }
                    else
                        move[y][x][cp + 2 * dp] = mov;

                    break;
                }
            }
            go(x, y, &x1, &y1, dp);
            if (check(x1, y1, m, l) && (data[y1][x1] != 0)) {
                if ((move[y][x][cp + 2 * dp] != mov) && (move[y][x][cp + 2 * dp] != -1)) {
                        per = mov - move[y][x][cp + 2 * dp];
                        while (n - per > mov)
                            n -= per;
                    }
                    else
                        move[y][x][cp + 2 * dp] = mov;
                //cout << mov << " " << x << " " << y << " " << dp << " " << cp << endl;
                x = x1;
                y = y1;
                ++mov;
                break;
            }
            else {
                if ((move[y][x][cp + 2 * dp] != mov) && (move[y][x][cp + 2 * dp] != -1)) {
                        per = mov - move[y][x][cp + 2 * dp];
                        while (n - per > mov)
                            n -= per;
                    }
                    else
                        move[y][x][cp + 2 * dp] = mov;
                ++cp;
                if (cp == 2) {
                    cp = 0;
                    ++dp;
                }
                dp = dp % 4;
                ++mov;
            }
        }
    }
    cout << data[y][x] << endl;
    return 0;
}