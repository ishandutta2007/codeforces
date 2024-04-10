#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string soort(string s){
    if(s.size()%2 != 0) return s;
    string s1 = "", s2 = "";
    for(unsigned i=0; i<s.size()/2; i++) s1 += s[i];
    for(unsigned i=s.size()/2; i<s.size(); i++) s2 += s[i];
    s1 = soort(s1);
    s2 = soort(s2);
    if(s1 > s2) return s2+s1;
    else return s1+s2;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string s1, s2;
    cin >> s1 >> s2;
    s1 = soort(s1);
    s2 = soort(s2);
    if(s1 == s2) cout << "YES";
    else cout << "NO";
    return 0;
}