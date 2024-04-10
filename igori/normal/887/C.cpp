#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
struct trio{
    int first;
    int second;
    int third;
};
struct long_trio{
    ll first;
    ll second;
    ll third;
};
const ll INF = 1e18 + 2;
const int LIT = 505;
const int BIG = 200001;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
//___________BAZE_________________
ll n, m, k, l, r, x, y, xk, yk, how, can, ks, ans1, ans2, ans3, b, c;
int a[25];
int grane[6][2][2];

            int ar[5] = {3, 1, 4, 5, 3};
//___________VARIABLES____________

int main()
{
    for (int i = 1; i <= 24; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++)
    {
        grane[i][0][0] = a[i * 4 + 1];
        grane[i][0][1] = a[i * 4 + 2];
        grane[i][1][0] = a[i * 4 + 3];
        grane[i][1][1] = a[i * 4 + 4];
    }
    vector<int> as;
    for (int i = 0; i < 6; i++)
    {
        if (grane[i][0][0] == grane[i][0][1] && grane[i][0][0] == grane[i][1][0] && grane[i][0][0] == grane[i][1][1])
        {
            as.pb(i);
        }
    }
    if (as.sz != 2)
    {
        r_NO;
    }
    if ((as[0] == 0 && as[1] == 2) || (as[0] == 1 && as[1] == 5) || (as[0] == 3 && as[1] == 4))
    {
        if (as[0] == 0 && as[1] == 2)
        {
            // 3 1 4 5
            int check = 0;
            for (int i = 0; i < 4; i++)
            if (grane[ar[i]][0][0] == grane[ar[i]][0][1] && grane[ar[i]][0][0] == grane[ar[i + 1]][1][0] && grane[ar[i + 1]][1][0] == grane[ar[i + 1]][1][1])
            {
                check++;
            }
            if (check == 4)
            {
                r_YES;
            }
            check = 0;
            swap(ar[1], ar[3]);
            for (int i = 0; i < 4; i++) {
            if (grane[ar[i]][0][0] == grane[ar[i]][0][1] && grane[ar[i]][0][0] == grane[ar[i + 1]][1][0] && grane[ar[i]][0][0] == grane[ar[i + 1]][1][1])
            {
                check++;
            }
            }
            //cout << check << endl;
            if (check == 4)
            {
                r_YES;
            }
        }
        if (as[0] == 1 && as[1] == 5)
        {
            // 0 4 2 3
            int check = 0;
            if (a[3] == a[4] && a[3] == a[18] && a[3] == a[20])
            check++;
            if (a[17] == a[19] && a[17] == a[11] && a[17] == a[12])
            check++;
            if (a[9] == a[10] && a[9] == a[13] && a[9] == a[15])
            check++;
            if (a[14] == a[16] && a[14] == a[1] && a[14] == a[2])
            check++;
            if (check == 4)
            {
                r_YES;
            }
            check = 0;
            if (a[3] == a[4] && a[3] == a[13] && a[3] == a[15])
            check++;
            if (a[17] == a[19] && a[17] == a[1] && a[17] == a[2])
            check++;
            if (a[9] == a[10] && a[9] == a[18] && a[9] == a[20])
            check++;
            if (a[14] == a[16] && a[14] == a[11] && a[14] == a[12])
            check++;
            if (check == 4)
            {
                r_YES;
            }
        }
        if (as[0] == 3 && as[1] == 4)
        {
            // 0 4 2 3
            int check = 0;
            if (a[3] == a[1] && a[3] == a[6] && a[3] == a[8])
            check++;
            if (a[5] == a[7] && a[5] == a[10] && a[5] == a[12])
            check++;
            if (a[9] == a[11] && a[9] == a[21] && a[9] == a[23])
            check++;
            if (a[24] == a[22] && a[24] == a[4] && a[24] == a[2])
            check++;
            if (check == 4)
            {
                r_YES;
            }
            check = 0;
            if (a[3] == a[1] && a[3] == a[21] && a[3] == a[23])
            check++;
            if (a[5] == a[7] && a[5] == a[4] && a[5] == a[2])
            check++;
            if (a[9] == a[11] && a[9] == a[6] && a[9] == a[8])
            check++;
            if (a[24] == a[22] && a[24] == a[10] && a[24] == a[12])
            check++;
            if (check == 4)
            {
                r_YES;
            }
        }
    }
    else
    {
        r_NO;
    }
    r_NO;
}