#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
string s;
int tmp_cnt=0;
int sol=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    for(int i=0;i<n;++i){
        if(s[i]=='x'){
            tmp_cnt++;
        }else{
            if(tmp_cnt>=3) sol+=tmp_cnt-2;
            tmp_cnt=0;
        }
    }
    if(tmp_cnt>=3) sol+=tmp_cnt-2;
    cout << sol;
    return 0;


}