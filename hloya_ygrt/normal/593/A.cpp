#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int alp[10000][30];
string s[10000];
int checkans(int a,int b)
{
    if (a>b) return a; else return b;
}
int tryq( int j, int a,int b) {
    int k2 = 0;
    for ( int l = 0; l < 30; l++ )
        k2 += alp[j][l];

    if ( k2 - alp[j][a] - alp[j][b] > 0 ) return false;

    return true;
}

int main()
{



    int n;
    cin>>n;
    int l,ans = 0;

    vector < int > ot;

    for (int j = 0; j <n;j++ ) {
        cin >> s[j];
        int sz = s[j].length();

        for ( l = 0;l<sz;l++ )
            alp[j][s[j][l]-'a']=1;

        ot.push_back( j );
    }

    for (int j=0;j<26;j++)
    for (l=j+1;l<26;l++) {
            int ta = 0;

            for ( int y = 0; y < ot.size(); y++ )
            if ( tryq( ot[y], j, l ) ) ta+=s[y].size();

            ans=checkans(ans,ta);
        }

    cout<<ans;
    return 0;
}