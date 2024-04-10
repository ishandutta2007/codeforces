#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int l[MAXN], r[MAXN];
void connect(int a, int b){
    r[a] = b;
    l[b] = a;
}
int las(int x){
    if(r[x] == 0) return x;
    return las(r[x]);
}
int main(){
    int n;
    cin >> n;
    vector<int> st;
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for(int i = 1; i <= n; i++){
        if(l[i] == 0) st.push_back(i);
    }
    vector<int> ends;
    for(auto x : st){
        ends.push_back(las(x));
    }
    for(int i = 0; i < (int)st.size() - 1; i++){
        connect(ends[i], st[i + 1]);
    }
    for(int i = 1; i <= n; i++){
        cout << l[i] << " " << r[i] << endl;
    }
    return 0;
}