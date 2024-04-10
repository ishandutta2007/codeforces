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

string s;
map<int,int> st,ss;
map<int,int> :: iterator it;
int n, x,y,xx,yy,m,c,b,ans,a[123456];
char ch;

int main() {
    cin>>n>>s;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='0') x++; else y++;   
    }
    cout<<abs(x-y);

    return 0;
}