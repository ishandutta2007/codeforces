#include <bits/stdc++.h>
using namespace std;

const int INF = 2*(1e9)+4;
const long long IINF = (1e18)+4;
const int NS = 104;
int N;
string s;

int main(){
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='o'){
            cnt1++;
        }
        else cnt2++;
    }

    if(cnt1==0){
        puts("YES");
    }
    else cnt2%cnt1==0? puts("YES"): puts("NO");

    return 0;
}