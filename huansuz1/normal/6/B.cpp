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
char a[1234][1234],r;
int n,k,ans,z,m,e,b[123];


int main() {
    cin>>n>>m>>r;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]==r) { 
                if (a[i-1][j]>= 'A' && a[i-1][j]<='Z') b[a[i-1][j]-'A']=1;
                if (a[i+1][j]>= 'A' && a[i+1][j]<='Z') b[a[i+1][j]-'A']=1;
                if (a[i][j-1]>= 'A' && a[i][j-1]<='Z') b[a[i][j-1]-'A']=1;
                if (a[i][j+1]>= 'A' && a[i][j+1]<='Z') b[a[i][j+1]-'A']=1;
            }
    b[r-'A']=0;
    for (int i=0; i<26; i++)
        ans+=b[i];
    cout<<ans;

    return 0;
}