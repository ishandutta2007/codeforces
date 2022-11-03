#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string s;
    vector<string> v;
    cin >> s;
    int i = 0, word_begin = -1;
    while(i < s.length()){
        if(i+3 <= s.length() && s.substr(i,3) == "WUB"){
            if(word_begin >= 0){
                v.push_back(s.substr(word_begin,i-word_begin));
            }
            word_begin = -1;
            i += 3;
        }else{
            if(word_begin == -1){
                word_begin = i;
            }
            i++;
        }
    }
    if(word_begin >= 0){
        v.push_back(s.substr(word_begin,i-word_begin));
    }
    for(int i=0; i<v.size(); i++){
        if(i){
            cout << " ";
        }
        cout << v[i];
    }
    return 0;
}