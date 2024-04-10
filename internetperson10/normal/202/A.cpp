#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    for(int a=0; a<=(s.size()/2); a++) {
        if(s.at(a)!=s.at(s.size()-a-1)) {
            return false;
        }
    }
    return true;
}

bool isGreater(string s1, string s2) {
    for(int a=0; a<min(s1.size(), s2.size()); a++) {
        if(s1.at(a)!=s2.at(a)) {
            if(s1.at(a)<s2.at(a)) return false;
            return true;
        }
    }
    if(s1.size()<s2.size()) return false;
    if(s1.size()>s2.size()) return true;
}

int main() {
    string s, maxsofar="a", sub="";
    cin >> s;
    for(int a=1; a<(1 << (s.size())); a++) {
        for(int b=0; b<s.size(); b++) {
            if(a & (1 << b)) {
                sub.append(s, b, 1);
            }
        }
        if(isPalindrome(sub)) {
            //cout << sub << '\n';
            if(isGreater(sub, maxsofar)) {
                maxsofar = sub;
            }
        }
        sub="";
    }
    cout << maxsofar;
}