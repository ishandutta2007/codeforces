#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i = 0;
    while(true) {
        if(i % 2 == 0) {
            cout << "next 0" << endl;
        } else {
            cout << "next 0 1" << endl;
        }
        int am;
        cin >> am;
        for(int j = 0; j < am; j++) {
            string s;
            cin >> s;
        }
        if(i % 2 == 1 && am == 2) {
            break;
        }
        ++i;
    }
    while(true) {
        cout << "next ";
        for(int j = 0; j < 10; j++) {
            cout << j << ' ';
        }
        cout << endl;
        int am;
        cin >> am;
        for(int j = 0; j < am; j++) {
            string s;
            cin >> s;
        }
        if(am == 1) {
            cout << "done" << endl;
            break;
        }
    }
}