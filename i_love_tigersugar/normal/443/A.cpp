#include<bits/stdc++.h>
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int main(void) {
    string s;
    getline(cin,s);
    set<char> ch;
    FORE(it,s) if ('a'<=*it && *it<='z') ch.insert(*it);
    cout<<ch.size();
    return 0;
}