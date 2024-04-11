#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
int N;
vector<int> v;
void print(vector<int> v) {
    cerr << "{";
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) cerr << ", ";
        cerr << v[i];
    }
    cerr << "}" << endl;
}

void h(vector<int> a) {
    vector<int> newv;
    for(int i = a.size() - 1; i >= 0; i--) {
        int sum = 0;
        for(int j = 0; j < i; j++) sum += a[j];
        for(int j = 0; j < a[i]; j++) {
            newv.push_back(v[sum + j]);
        }
    }
    swap(newv, v);
}

vector<vector<int>> ans;

void f() {
    int r = N - 1;
    vector<int> a;
    while(r != -1) {
        int mindex = r;
        for(int j = 0; j <= r; j++) {
            if(v[mindex] > v[j]) mindex = j;
        }
        a.push_back(r - mindex + 1);
        r = mindex - 1;
    }
    reverse(a.begin(), a.end());
    /*
    cout << a.size();
    for(auto tmp : a) cout << " " << tmp;
    cout << endl;
    */
    if(a.size() >= 2) ans.push_back(a);
    h(a);
    return;
}

void g() {
    int l = 0;
    vector<int> a;
    while(l != N) {
        int mindex = l;
        for(int j = l; j < N; j++) {
            if(v[mindex] > v[j]) mindex = j;
        }
        a.push_back(mindex - l + 1);
        l = mindex + 1;
    }
    /*
    cout << a.size();
    for(auto tmp : a) cout << " " << tmp;
    cout << endl;
    */
    if(a.size() >= 2) ans.push_back(a);
    h(a);
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        v[i]--;
    }
    for(int q = 0; q < N; q++) {
        if((N - q) % 2 == 1) {
            f();
        } else {
            g();
        }
        //print(v);
    }
    cout << ans.size() << endl;
    for(auto v : ans) {
        cout << v.size();
        for(auto tmp : v) {
            cout << " " << tmp;
        }
        cout << endl;
    }
    return 0;
}