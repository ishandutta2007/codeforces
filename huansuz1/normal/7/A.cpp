#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>

#define ll long long
#define f first
#define s second
#define mp make_pair

using namespace std;
queue < int > q;
string s[1235];
char a[12][12];
int n,k,al,bo,z,m,e,b[123456],x,y;


int main() {
    for (int i=1; i<=8; i++)
        for (int j=1; j<=8; j++)
            cin>>a[i][j];
    for (int i=1; i<=8; i++){
        int w=0;
        for (int j=1; j<=8; j++)
            if (a[i][j]!='B') {w=1; break; } 

        if (w==0) {z++;
            for (int j=1; j<=8; j++)
                a[i][j]='b';
        }
    }
    
    for (int i=1; i<=8; i++){
        int w=0,e=0;
        for (int j=1; j<=8; j++) {
            if (a[j][i]!='B' && a[j][i]!='b') {w=1; break; } 
            if (a[j][i]=='B') e=1;
        }
        if (w==0 && e==1) z++;
    }
    cout<<z;


    return 0;
}