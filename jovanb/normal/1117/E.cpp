#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int p1[10005];
int p2[10005];
int p3[10005];
int f[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string t;
    cin >> t;
    int n = t.size();
    for(int i=0; i<n; i++){
        int x = i;
        p1[i] = x/(26*26);
        x %= 26*26;
        p2[i] = x/26;
        x %= 26;
        p3[i] = x;
    }
    string s = "";
    string r1, r2, r3;
    for(int i=0; i<n; i++){
        s += p1[i]+'a';
    }
    cout << "? " << s << endl;
    cin >> r1;
    s = "";
    for(int i=0; i<n; i++){
        s += p2[i]+'a';
    }
    cout << "? " << s << endl;
    cin >> r2;
    s = "";
    for(int i=0; i<n; i++){
        s += p3[i]+'a';
    }
    cout << "? " << s << endl;
    cin >> r3;
    for(int i=0; i<n; i++){
        int x = 26*26*(r1[i]-'a') + 26*(r2[i]-'a') + (r3[i]-'a');
        f[x] = i;
    }
    cout << "! ";
    for(int i=0; i<n; i++) cout << t[f[i]];
    cout << endl;
    return 0;
}