#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;

#define N 3333

int k,n;
string a[4*N];

string getS(string& a) {
    string res = "";
    int c = k;
    for (int i = (int) a.size() - 1; i >= 0; --i) {
        if (a[i] == 'a' || a[i] == 'o' || a[i] == 'u' || a[i] == 'e' || a[i] == 'i') c--;
        if (c == 0) { 
            res = a.substr(i);
            break;
        }
    }
    if (c) return "";
    return res;
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> n >> k;
    for (int i = 0; i < 4*n; ++i) {
        string s;
        cin >> s;
        a[i] = getS(s);
        if (a[i] == "") {
            puts("NO");
            return 0;
        }
    }
    
    bool aaaa = true, aabb = true, abab = true, abba = true;
    for (int i = 0; i < n; ++i) {
        int j = i*4;
        if (!(a[j] == a[j + 1] && a[j] == a[j + 2] && a[j] == a[j + 3])) aaaa = false;
        if (!(a[j] == a[j + 1] && a[j + 2] == a[j + 3])) aabb = false;
        if (!(a[j] == a[j + 2] && a[j + 1] == a[j + 3])) abab = false;
        if (!(a[j] == a[j + 3] && a[j+1] == a[j + 2])) abba = false;
    }
    
    if (aaaa) {
        puts("aaaa");
        return 0;
    }
    if (abba) {
        puts("abba");
        return 0;
    }
    if (abab) {
        puts("abab");
        return 0;
    }
    if (aabb) {
        puts("aabb");
        return 0;
    }
    puts("NO");
    
    return 0;
}