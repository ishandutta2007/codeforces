#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 5e5+1;
vector<int> m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    m.resize(q);
    struct cm {
        bool operator()(int a,int b) {
            return m[a] < m[b] or (m[a]==m[b] and a>b);
        }
    };
    priority_queue<int,vector<int>, cm> sm;
    queue<int> st;
    int nc=1;
    bitset<mxN> served;
    for(int i=0;i<q;++i) {
        int t; cin >> t;
        if(t==1) {
            cin >> m[nc];
            st.push(nc);
            sm.push(nc++);
        } else if(t==2) {
            while(!st.empty()) {
                int cur = st.front();
                st.pop();
                if(!served[cur]) {
                    served[cur] = true;
                    cout << cur << ' ';
                    break;
                }
            }
        } else {
            while(!sm.empty()) {
                int cur = sm.top();
                sm.pop();
                if(!served[cur]) {
                    served[cur] = true;
                    cout << cur << ' ';
                    break;
                }
            }
        }
    }
}