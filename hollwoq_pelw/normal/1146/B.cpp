#include <bits/stdc++.h>
using namespace std;
int main(){
    string t, r="";
    cin >> t;
    for (char c:t){
        if (c!='a') r+=c;
    }
    //cout << r << endl;
    int n = r.length(), k = t.length();
    if (n % 2) return cout << ":(", 0;
    string s1 = r.substr(0, n/2), s2 = r.substr(n/2), s3 = t.substr(k-n/2);
    //cout << s1 << endl;
    //cout << s2 << endl;
    //cout << s3 << endl;
    if (s1 != s2 || s1 != s3 || s2 != s3) return cout << ":(", 0;
    cout << t.substr(0,k-n/2);
}