#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<int,int> st,ss;
map<int,int> :: iterator it;
int n, x,y,xx,yy,c,b,ans,a[123][123];
char ch;

int main() {
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>x>>y>>xx>>yy;
        for (int j=min(x,xx); j<=max(x,xx); j++){
            for (int jj=min(y,yy); jj<=max(y,yy); jj++)
                a[j][jj]++;
        }

    }
    for (int i=0; i<=100; i++)
        for (int j=0; j<=100; j++)
            ans+=a[i][j];
    cout<<ans;


    return 0;
}