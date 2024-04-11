#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    map<char, int> mp;
    for(char a = '0'; a <= '9'; a++){
        mp[a] = (int)a - 48;
    }
    //cout << mp['6'] << endl;
    //cout.precision(10);
    int n;
    cin >> n;
    string k;
    cin >> k;
    string number;
    for(int i = 0; i < n; i++){
        if(k[i] == '0'){
            continue;
        }
        number.push_back(k[i]);
    }
    if(number.size() == 0){
        cout << "YES" << endl;
        return 0;
    }
    if(number.size() == 1){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 1; i <= 900; i++){
        int kazu = 0;
        int sum = 0;
        for(int l = 0; l < number.size(); l++){
            sum += mp[number[l]];
            if(sum > i){
                break;
            }
            if(sum == i){
                sum = 0;
                kazu++;
            }
        }
        if(kazu <= 1){
            continue;
        }
        if(sum != 0){
            continue;
        }
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}