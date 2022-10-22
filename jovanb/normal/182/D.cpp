#include <bits/stdc++.h>
using namespace std;

vector <int> l;

bool check(string s, string str){
    string sp = s;
    while(s.size() < str.size()) s += sp;
    return s == str;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    int x = __gcd(n1, n2);
    for(int i=1; i*i<=x; i++){
        if(i*i == x) l.push_back(i);
        else if(x%i == 0){
            l.push_back(i);
            l.push_back(x/i);
        }
    }
    int br = 0;
    for(auto c : l){
        string s = "";
        for(int i=0; i<c; i++){
            s += s1[i];
        }
        if(check(s, s1) && check(s, s2)) br++;
    }
    cout << br;
    return 0;
}