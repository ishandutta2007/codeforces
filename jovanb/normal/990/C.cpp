#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <int, int> del1;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll br=0;
    while(n--){
        string s;
        cin >> s;
        int x = s.size();
        int bro=0, brz=0;
        bool mozepref=1, mozesuf=1;
        for(int i=0; i<x; i++){
            if(s[i] == '(') bro++;
            else brz++;
            if(brz > bro) mozepref = 0;
        }
        bro=0, brz=0;
        for(int i=x-1; i>=0; i--){
            if(s[i] == '(') bro++;
            else brz++;
            if(bro > brz) mozesuf = 0;
        }
        if(mozepref == 0 && mozesuf == 0) continue;
        int del = bro-brz;
        if(del == 0){
            br += 2*del1[0];
            del1[del]++;
            br++;
            continue;
        }
        del1[del]++;
        br += del1[-del];
    }
    cout << br;
    return 0;
}