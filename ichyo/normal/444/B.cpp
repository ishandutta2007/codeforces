#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long LL;
const int MAX_N = 100010;
int a[MAX_N];
int b[MAX_N];
int n, d;
long long global_x;
int getNextX() {
    global_x = (global_x * 37 + 10007) % 1000000007;
    return global_x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
    while(cin >> n >> d >> global_x){
        //cerr << n << " " << d << " " << global_x << endl;
        initAB();
        const int BOUND = 10000;
        if(d <= BOUND) {
            //cerr << "round1" << endl;
            vector<int> index;
            REP(i, n) if(b[i] == 1) {
                index.push_back(i);
            }
            for(int i = 0; i < n; i++) {
                int ans = 0;
                for(int idx : index) {
                    int j = i - idx;
                    if(j < 0) break;
                    ans = max(ans, a[j]);
                }
                printf("%d\n", ans);
            }
        } else {
            //cerr << "round2" << endl;
            vector<int> v;
            for(int i = 0; i < n; i++) {
                int lb = -1, ub = v.size();
                while(ub - lb > 1) {
                    int k = (lb + ub) / 2;
                    if(a[ v[k] ] < a[i]) {
                        lb = k;
                    } else {
                        ub = k;
                    }
                }
                v.insert(v.begin() + lb + 1, i);
                /*
                   auto p = make_pair(a[i], i);
                   vp.insert(lower_bound(vp.begin(), vp.end(), p), p);
                    int ans = 0;
                    for(int j = vp.size() - 1; j >= 0; j--) {
                        // i - vp[j].second == index
                        int index = i - vp[j].second;
                        if(b[index] == 1) {
                            ans = vp[j].first;
                            break;
                        }
                    }
                */
                int ans = 0;
                for(int j = v.size() - 1; j >= 0; j--) {
                    int index = i - v[j];
                    if(b[index] == 1) {
                        ans = a[ v[j] ];
                        break;
                    }
                }
                printf("%d\n", ans);
                //cout << ans << endl;
            }
        }
    }
    return 0;
}