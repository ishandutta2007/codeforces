#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int connected = 0;
    if(s[0] == 'G') connected++;
    for(int i = 1; i < n; i++){
        if(s[i] == 'G' && s[i - 1] == 'S') connected++;
    }
    //cout << connected<< endl;
    vector<int> gold;
    if(s[0] == 'G') gold.push_back(1);
    for(int i = 1; i < n; i++){
        if(s[i] == 'G' && s[i - 1] == 'S'){
            gold.push_back(1);
            continue;
        }
        if(s[i] == 'G') gold.back()++;
        if(s[i] == 'S' && s[i - 1] == 'S') gold.push_back(0);
    }
    for(int i = 0; i < gold.size(); i++){
        //cout << gold[i] << endl;
    }
    //return 0;
    if(connected == 0){
        cout << 0 << endl;
        return 0;
    }
    if(connected == 1){
        for(int i = 0; i < gold.size(); i++){
            if(gold[i] > 0){
                cout << gold[i] << endl;
                return 0;
            }
        }
    }
    if(connected == 2){
        for(int i = 0; i < gold.size() - 1; i++){
            if(gold[i] > 0 && gold[i + 1] > 0){
                cout << gold[i] + gold[i + 1] << endl;
                return 0;
            }
        }
        int maxi = 0;
        for(int i = 0; i < gold.size(); i++){
            maxi = max(maxi, gold[i]);
        }
        cout << maxi + 1 << endl;
        return 0;
    }
    int maxi = 0;
    for(int i = 0; i < gold.size() - 1; i++){
        maxi = max(maxi, gold[i] + gold[i + 1] + 1);
    }
    cout << maxi << endl;
    return 0;
}