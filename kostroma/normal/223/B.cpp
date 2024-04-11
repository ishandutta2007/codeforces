//#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <memory.h>
#include <stack>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long li;
#define all(a) a.begin(), a.end()
typedef long double ld;
typedef pair<int,int> pi;

//#define FILE "chess"

void solve();
int main(){
#ifdef Kostroma
    freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
#else
    //freopen (FILE ".in", "r", stdin);
    //freopen (FILE ".out", "w", stdout);
#endif
    
    int t = 1;
    while (t--)
        solve();
    return 0;
}

//#define int li
const int MAXN = 200500;
string s, t;
int pref[MAXN], suf[MAXN];
int num[MAXN][30];

void solve(){
    cin>>s>>t;
    int j = 0;
    for (int i=0; i<s.length(); ++i)
        if (j < t.length() && s[i] == t[j]){
            pref[i] = j;
            ++j;
        }
        else
            pref[i] = j - 1;
    j = t.length() - 1;
    for (int i=s.length() - 1; i>=0; --i)
        if (j < t.length() && s[i] == t[j]){
            suf[i] = j;
            --j;
        }
        else
            suf[i] = j + 1;
    
    /*for (int i=0; i<s.length(); ++i)
        cout<<pref[i]<<' '<<suf[i]<<endl;*/
    
    num[0][t[0]-'a'] = 1;
    //cout<<t[0]-'a';
    for (int i=1; i<=t.length(); ++i){
        if (i < t.length())
            num[i][t[i]-'a'] ++;
        for (char c = 'a'; c <= 'z'; ++c)
            num[i][c-'a'] += num[i-1][c-'a'];
    }
   /* for (int i=0; i<t.length(); ++i){
        for (char c ='a'; c <= 'z'; ++c)
            cout<<num[i][c-'a']<<' ';
        cout<<endl;
    }*/
    for (int i=0; i<s.length(); ++i){
        int cur1 = ((i==0)?-1:pref[i - 1]), cur2 = ((i + 1 == s.length())?t.length():suf[i + 1]);
        ++cur1; --cur2;
        //cout<<i<<' '<<cur1<<' '<<cur2<<endl;
        if (((cur2 <= 0)?0:num[cur2 - 1][s[i]-'a']) >= ((cur1 <= -1)?0:num[cur1][s[i]-'a'])){
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}