#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int k;
    cin >> k;
    vector< vector< pair<long long, int> > > a(k);
    for(int i = 0; i < k; i++){
        int size;
        cin >> size;
        vector<pair<long long, int> > in(size);
        for(int j = 0; j < size; j++){
            pair<long long, int> in2;
            long long in3;
            cin >> in3;
            in2.first = in3;
            in2.second = j;
            in[j] = in2;
        }
        a[i] = in;
    }
    long long sum[200100];
    for(int i = 0; i < k; i++){
        sort(a[i].begin(), a[i].end());
        sum[i] = 0;
        for(int j = 0; j < a[i].size(); j++){
            sum[i] += a[i][j].first;
        }
    }
    vector<pair<long long, int> > ans;
    for(int i = 0; i < k; i++){
        pair<long long, int> in0;
        in0.first = sum[i] - a[i][0].first;
        in0.second = i;
        ans.push_back(in0);
        for(int j = 1; j < a[i].size(); j++){
            if(a[i][j].first == a[i][j - 1].first){
                continue;
            }
            pair<long long, int> in;
            in.first = sum[i] - a[i][j].first;
            in.second = i;
            ans.push_back(in);
        }
    }
    sort(ans.begin(), ans.end());
    int checker = 0;
    while(true){
        if(checker >= (ans.size() - 1)){
            cout << "NO" << endl;
            return 0;
        }
        if(ans[checker].first == ans[checker + 1].first){
            if(ans[checker].second != ans[checker + 1].second){
                break;
            }
        }
        checker++;
    }
    cout << "YES" << endl;
    long long value = ans[checker].first;
    int seq1 = ans[checker].second;
    int seq2 = ans[checker + 1].second;
    for(int j = 0; j < a[seq1].size(); j++){
        if(value == (sum[seq1] - a[seq1][j].first)){
            cout << seq1 + 1 << " " << a[seq1][j].second + 1 << endl;
            break;
        }
    }
    for(int j = 0; j < a[seq2].size(); j++){
        if(value == (sum[seq2] - a[seq2][j].first)){
            cout << seq2 + 1 << " " << a[seq2][j].second + 1 << endl;
            break;
        }
    }
    return 0;
}