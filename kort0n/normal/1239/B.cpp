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
queue<int> Right;
stack<int> Left;
int Match[300050];
int NumLeft = 0;
int root;
vector<int> children[300050];
int parent[300050];
int start = 0;
int startval = -1;
int ansval = -1;
i_i ansindex = {1, 1};
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    root = N;
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') NumLeft++;
    }
    if(NumLeft * 2 != N) {
        cout << "0" << endl;
        cout << "1 1" << endl;
        return 0;
    }
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '(') {
            Left.push(i);
        } else {
            if(!Left.empty()) {
                int pos = Left.top();
                Left.pop();
                Match[pos] = i;
                Match[i] = pos;
            } else {
                Right.push(i);
            }
        }
    }
    while(!Left.empty()) {
        int one = Left.top();
        int two = Right.front();
        Left.pop();
        Right.pop();
        Match[one] = two;
        Match[two] = one;
    }
    for(int i = 0; i < N; i++) {
        if(S[i] == ')') continue;
        int nowval = (Match[i] - i + N) % N;
        if(nowval > startval) {
            start = i;
            startval = nowval;
        }
    }
    /*
    for(int i = 0; i < N; i++) cerr << Match[i] << " ";
    cerr << endl;
    //*/
    cerr << start << endl;
    int nowpos = root;
    for(int delta = 0; delta < N; delta++) {
        int index = (start + delta) % N;
        if(S[index] == '(') {
            children[nowpos].push_back(index);
            parent[index] = nowpos;
            nowpos = index;
        } else {
            nowpos = parent[nowpos];
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        cerr << "---" << i << "---" << endl;
        for(auto v : children[i]) cerr << v << " ";
        cerr << endl;
    }
    */
    /*
    for(int i = 0; i < N; i++) cerr << parent[i] << " ";
    cerr << endl;
    //*/
    ansval = children[root].size();
    for(auto now : children[root]) {
        //cerr << "searching: " << now << endl;
        int nowval = 1 + children[now].size();
        if(nowval > ansval) {
            ansindex.first = now;
            ansindex.second = Match[now];
            ansval = nowval;
        }
        for(auto v : children[now]) {
            nowval = children[root].size() + 1 + children[v].size();
            //cerr << "depth: 2 " << v << " "<< nowval << endl;
            if(nowval > ansval) {
                ansindex.first = v;
                ansindex.second = Match[v];
                ansval = nowval;
            }
        }
    }
    cout << ansval << endl;
    cout << ansindex.first + 1 << " " << ansindex.second + 1 << endl;
    return 0;
}