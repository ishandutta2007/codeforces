#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int mxN = 1e5;
int main() {

    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin >> a[i];
    int firsth = 1;
    vector<int> three,two;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;++i) {
        if(a[i]==3) {
            if(!three.empty()) {
                int height = three.back();
                ans.push_back({height,i});
                three.back()=firsth;
                ans.push_back({firsth++,i});
            } else {
                three.push_back(firsth);
                ans.push_back({firsth++,i});
            }
        } else if(a[i]==2) {
            if(!three.empty()) {
                int height = three.back();
                ans.push_back({height,i});
                three.pop_back();
                two.push_back(firsth);
                ans.push_back({firsth++,i});
            } else {
                two.push_back(firsth);
                ans.push_back({firsth++,i});
            }
        } else if(a[i]==1) {
            if(!two.empty()) {
                int height = two.back();
                two.pop_back();
                ans.push_back({height,i});
            }else if(!three.empty()) {
                int height = three.back();
                ans.push_back({height,i});
                three.pop_back();
                ans.push_back({firsth++,i});
            } else {
                ans.push_back({firsth++,i});
            }
        }
    }
    if(two.empty() and three.empty() and firsth <= n+1) {
        cout << ans.size() << endl;
        // bool grid[10][10]={};
        for(auto p: ans) {
            cout << p.first << ' ' << p.second << endl;
            // grid[p.first][p.second]=true;
        }
        
        // for(int row=1;row<=n;++row) {
        //     for(int col=1;col<=n;++col) {
        //         cout << grid[row][col]?'X':'.';
        //     } cout << endl;
        // }

    } else {
        cout << "-1\n";
    }
}