#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int counts[3][3];
        int xcounts[3][3];
        int ocounts[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                counts[i][j] = 0;
                xcounts[i][j] = 0;
                ocounts[i][j] = 0;
            }
        }
        vector<vector<char>> table(n, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                table[i][j] = s[j];
                int ci = (i + j) % 3;
                int cj = (((j - i) % 3) + 3) % 3;
                if (s[j] != '.') counts[ci][cj]++;
                if (s[j] == 'X') xcounts[ci][cj]++;
                if (s[j] == 'O') ocounts[ci][cj]++;
            }
        }

        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                k += counts[i][j];
            }
        }

        char changes[3][3];
        int sum0, sum1, sum2;
        int x0, x1, x2;
        int o0, o1, o2;
        sum0 = counts[0][0] + counts[2][0] + counts[1][0];
        sum1 = counts[0][1] + counts[1][1] + counts[2][1];
        sum2 = counts[0][2] + counts[1][2] + counts[2][2];
        x0 = xcounts[0][0] + xcounts[1][0] + xcounts[2][0];
        x1 = xcounts[0][1] + xcounts[1][1] + xcounts[2][1];
        x2 = xcounts[0][2] + xcounts[1][2] + xcounts[2][2];
        o0 = ocounts[0][0] + ocounts[1][0] + ocounts[2][0];  
        o1 = ocounts[0][1] + ocounts[1][1] + ocounts[2][1];
        o2 = ocounts[0][2] + ocounts[1][2] + ocounts[2][2];
        if (sum0 >= sum1 && sum0 >= sum2) {
          changes[0][0] = '.';
          changes[1][0] = '.';
          changes[2][0] = '.';
          changes[0][1] = 'X';
          changes[1][1] = 'X';
          changes[2][1] = 'X';
          changes[0][2] = 'X';
          changes[1][2] = 'X';
          changes[2][2] = 'X';
          if (x1 + o2 >= x2 + o1) {
            changes[0][2] = 'O';
            changes[1][2] = 'O';
            changes[2][2] = 'O';
          } else {
              changes[0][1] = 'O';
              changes[1][1] = 'O';
              changes[2][1] = 'O';
          }
        } else if (sum1 >= sum0 && sum1 >= sum2) {
          changes[0][1] = '.';
          changes[1][1] = '.';
          changes[2][1] = '.';
          changes[0][0] = 'X';
          changes[1][0] = 'X';
          changes[2][0] = 'X';
          changes[0][2] = 'X';
          changes[1][2] = 'X';
          changes[2][2] = 'X';
          if (x0 + o2 >= x2 + o0) {
            changes[0][2] = 'O';
            changes[1][2] = 'O';
            changes[2][2] = 'O';
          } else {
              changes[0][0] = 'O';
              changes[1][0] = 'O';
              changes[2][0] = 'O';
          }
        } else {
          changes[0][2] = '.';
          changes[1][2] = '.';
          changes[2][2] = '.';
          changes[0][1] = 'X';
          changes[1][1] = 'X';
          changes[2][1] = 'X';
          changes[0][0] = 'X';
          changes[1][0] = 'X';
          changes[2][0] = 'X';
          if (x0 + o1 >= x1 + o0) {
            changes[0][1] = 'O';
            changes[1][1] = 'O';
            changes[2][1] = 'O';
          } else {
              changes[0][0] = 'O';
              changes[1][0] = 'O';
              changes[2][0] = 'O';
          }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ci = (i + j) % 3;
                int cj = ((j - i) % 3 + 3) % 3;
                if (changes[ci][cj] == 'X' && table[i][j] == 'O') table[i][j] = 'X';
                if (changes[ci][cj] == 'O' && table[i][j] == 'X') table[i][j] = 'O';
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << table[i][j];
            }
            cout << "\n";
        }

    }
}