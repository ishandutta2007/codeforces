#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;
map<string, int> cnt;
string s;
int k;
int dfs() {
    string name;
    int res = 0;
    while(isupper(s[k])) {
        name += s[k++];
    }
    if(s[k] == '.') {
        k++;
        res += cnt[name];
    } else {
        k++;
        res += cnt[name];
        cnt[name]++;
        while(true) {
            res += dfs();
            if(s[k++] == '.') {
                break;
            }
        }
        cnt[name]--;
    }
    return res;
}

int main(){
    while(cin >> s){
        k = 0;
        cout << dfs() << endl;
    }
    return 0;
}