#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
const int mxN = 15004;

void solve() {
    int n; cin >> n;
    if(n<=2) { 
        cout << "0\n";
        return;
    }
    int a[mxN];
    int cnt = n+1;
    int last = 0;
    vector<pair<int,int>> ans;
    auto go = [&](int c,int d,bool same=false) {
        ans.emplace_back(c,d);
        if(!same) cnt++;
        a[c]=a[d]=cnt;
    };
    for(int i=1;i<=n;++i) a[i] = i;

    for(int i=1;(1<<i)<=n;++i) {
        int pow = (1<<i);
        for(int j=1;j+pow-1 <= n;j+=pow) {
            for(int k=0;k<pow/2;++k) {
                go(j+k,j+k+pow/2,k);
                last = j+k+pow/2;
            }
        }
        // for(int i=1;i<=n;++i) {
        //     cout << a[i] << ' ';
        // } cout << endl;
    }
    int wrong = n;
    int beginlast = last;
    vector<int> prev;

    int prevwrong=a[wrong];
    while(wrong > beginlast) {
        bool firstry = a[wrong] == prevwrong;
        prevwrong=a[wrong];
        bool my = false;
        vector<int> cur;
        if(firstry) {
            while(a[wrong]==prevwrong  and (prev.size()==0 or cur.size() < prev.size())) {
                go(last,wrong,my);
                cur.push_back(wrong);
                cur.push_back(last);
                my = true;
                last--;
                wrong--;
            }
            if(cur.size()==prev.size()) {
                vector<int> future;
                my=false;
                for(int i=0;i<(int)cur.size();++i) {
                    go(cur[i],prev[i],my);
                    my=true;
                    future.push_back(cur[i]);
                    future.push_back(prev[i]);
                }
                cur = future;
            }
            prev =cur;
            firstry = false;
        } else {
            while(a[wrong]==prevwrong and !prev.empty()) {
                go(prev.back(),wrong,my);
                cur.push_back(wrong);
                cur.push_back(prev.back());
                prev.pop_back();
                my = true;
                wrong--;
            }
            prev = cur;
        }
        // for(int i=1;i<=n;++i) {
        //     cout << a[i] << ' ';
        // } cout << endl;

    }
    cout << ans.size() << endl;
    for(auto p: ans) {
        cout << p.first << ' ' << p.second << endl;
    }
    


}
int main() {
    solve();
}