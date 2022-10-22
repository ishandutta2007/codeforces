#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}

int main() {

    int n,m,x,y,x1,y1;
    cin >> n;
    string s;
    cin >> s;
    ll ans=1;
if (s[0]==s[n-1]){
    char c=s[0];
    ll co=1;
ll ii=1;
while(s[ii]==c){
    co++;
    ii++;
}
ii=n-1;
ll co1=0;
while(s[ii]==c){
    co1++;
    ii--;
}
co++;
co1++;
cout << (co*co1)%998244353;
}
else{
    char c=s[0],c1=s[n-1];
    ll co=1;
ll ii=1;
while(s[ii]==c){
    co++;
    ii++;
}
ii=n-2;
ll co1=1;
while(s[ii]==c1){
    co1++;
    ii--;
}
co++;
co1++;
cout << (co+co1-1)%998244353;
}








    return 0;
}