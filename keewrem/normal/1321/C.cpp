#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,k;

    int n;
    cin >> n >> s;
    bool q = 0;
    vector<int> v;
    for(int i = 'z'; i > 'a'; i--){
        v.clear();
        q = 0;
        for(int j = 0; j < s.size(); j++){
            if (s[j]==i-1)q = 1;
            if (s[j]!=i && s[j]!=i-1)q = 0;
            if (q == 1 && s[j] == i){v.push_back(j);}
        }
        q = 0;
        for(int j = s.size()-1; j >=0; j--){
            if (s[j]==i-1)q = 1;
            if (s[j]!=i && s[j]!=i-1)q = 0;
            if (q == 1 && s[j] == i)v.push_back(j);
        }
        for(auto x: v)s[x]=' ';
        k = "";
        for(auto x: s)if(x!=' ')k.push_back(x);
        //cout << s<<"\n";
        swap(s,k);
    }
    cout << n-s.size();
    return 0;
}