#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N, K;
int a[105000];
int r[2], l[2];
set<int> st[2];

int nowr[2], nowl[2];

bool lose() {
    for(int index = 1; index + K - 1 <= N; index++) {
        for(int num = 0; num <= 1; num++) {
            bool nowlose = false;
            nowr[num] = max(r[num], index + K - 1);
            nowl[num] = min(l[num], index);
            int inv = 1 - num;
            nowr[inv] = r[inv];
            nowl[inv] = l[inv];
            if(nowr[inv] <= index + K - 1) {
                auto itr = st[inv].lower_bound(index);
                if(itr != st[inv].begin()) itr--;
                if(*itr < index) nowr[inv] = *itr;
                else nowr[inv] = 0;
            }
            if(nowl[inv] >= index) {
                auto itr = st[inv].lower_bound(index + K);
                if(itr != st[inv].end()) nowl[inv] = *itr;
                else nowl[inv] = N + 1;
            }
            for(int i = 0; i <= 1; i++) {
                if(nowr[i] - nowl[i] <= K - 1) nowlose = true;
            }
            if(!nowlose) return false;
        }
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> N >> K >> S;
    for(int i = 0; i < S.size(); i++) {
        a[i+1] = S[i] - '0';
    }
    for(int i = 0; i < 2; i++) {
        r[i] = 0;
        l[i] = N + 1;
    }
    for(int i = 1; i <= N; i++) {
        st[a[i]].insert(i);
        chmax(r[a[i]], i);
        chmin(l[a[i]], i);
    }
    for(int i = 0; i < 2; i++) {
        //cerr << l[i] << " " << r[i] << endl;
        if(r[i] == 0) {
            cout << "tokitsukaze" << endl;
            return 0;
        }
        if(r[i] - l[i] <= K - 1) {
            cout << "tokitsukaze" << endl;
            return 0;
        }
    }
    if(lose()) {
        cout << "quailty" << endl;
    } else  cout << "once again" << endl;
    return 0;
}