#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

bool judge(vector<string>& w, string& s){
    string t;
    REP(i, w.size()){
        t += "<3" + w[i];
    }
    t += "<3$";
    int k = 0;
    REP(i, s.size()){
        if(t[k] == s[i]) k++;
    }
    return t[k] == '$';
}

int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    REP(i, n) cin >> w[i];
    string s;
    cin >> s;
    if(judge(w, s)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}