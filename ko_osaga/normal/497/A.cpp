#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> pi;

string s[105];

int lex_order(int col, int st, int e){
    for (int j=st; j<e; j++) {
        if(s[j][col] > s[j+1][col]) return 0;
    }
    return 1;
}

int n, m;
set<pi> st;

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    int cnt = 0;
    st.insert(pi(0,n-1));
    for (int i=0; i<m; i++) {
        int bad = 0;
        for (auto &j : st){
            if(!lex_order(i,j.first,j.second)){
                bad = 1;
                break;
            }
        }
        if(bad){
            cnt++;
            continue;
        }
        else{
            pi arr[105];
            int pt = 0;
            for (auto &j : st){
                for (int k=j.first; k<=j.second; ) {
                    int e = k;
                    while (e <= j.second && s[k][i] == s[e][i]) {
                        e++;
                    }
                    arr[pt++] = pi(k,e-1);
                    k = e;
                }
            }
            st.clear();
            for (int i=0; i<pt; i++){
                st.insert(arr[i]);
            }
        }
    }
    cout << cnt;
}