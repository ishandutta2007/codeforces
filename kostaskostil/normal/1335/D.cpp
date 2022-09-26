#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax=2e5+100;

string s[9];

void ch(int i, int j){
    if (s[i][j]=='9') s[i][j]='1';
    else s[i][j]++;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        for (int i=0; i<9; i++)
            cin>>s[i];
        ch(0, 0);
        ch(1, 3);
        ch(2, 6);
        ch(3, 1);
        ch(4, 4);
        ch(5, 7);
        ch(6, 2);
        ch(7, 5);
        ch(8, 8);
        for (int i=0; i<9; i++)
            cout<<s[i]<<"\n";
    }
    return 0;
}