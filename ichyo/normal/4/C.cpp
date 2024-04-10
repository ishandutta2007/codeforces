#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int N;
    cin >> N;
    unordered_map<string, int> st;
    REP(i, N){
        string s;
        cin >> s;
        if(st[s] == 0){
            cout << "OK" << endl;
        }else{
            cout << s << st[s] << endl;
        }
        st[s]++;
    }

    return 0;
}