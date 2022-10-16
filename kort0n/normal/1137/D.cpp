#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
string G[3];
void GO(int i) {
    for(int j = 0; j < G[i].size(); j++) {
        cout << " " << G[i][j];
    }
}

int main() {
    //cout.precision(10);
    for(char i = '0'; i <= '3'; i++) {
        G[0].push_back(i);
        G[1].push_back(i + 4);
    }
    G[2] = "9";
    G[1].push_back('8');
    int zero = 0;
    string dust;
    int gomi;
    while(true) {
        cout << "next";
        GO(0);
        cout << endl;
        cin >> gomi;
        for(int i = 0; i < gomi; i++) cin >> dust;
        cout << "next";
        GO(0);
        GO(1);
        cout << endl;
        cin >> gomi;
        for(int i = 0; i < gomi; i++) cin >> dust;
        zero++;
        if(gomi == 2) break;
    }
    int c = 0;
    while(true) {
        c++;
        cout << "next";
        GO(0);
        cout << endl;
        cin >> gomi;
        for(int i = 0; i < gomi; i++) cin >> dust;
        if(gomi == 2) break;
    }
    int hoge_one = zero - 1;
    hoge_one %= c;
    while(hoge_one < c - 1) {
        cout << "next";
        GO(0);
        GO(1);
        cout << endl;
        cin >> gomi;
        for(int i = 0; i < gomi; i++) cin >> dust;
        hoge_one++;
    }
    while(true) {
        cout << "next";
        GO(0);
        GO(1);
        GO(2);
        cout << endl;
        cin >> gomi;
        for(int i = 0; i < gomi; i++) cin >> dust;
        if(gomi == 1) break;
    }
    /*
    while((zero - t) % c != 0) {
        zero++;
        cout << "next";
        GO(0);
        GO(1);
        cout << endl;
        cin >> gomi;
        for(int i = 0; i < gomi; i++) cin >> dust;
    }
    */
    cout << "done" << endl;
    return 0;
}