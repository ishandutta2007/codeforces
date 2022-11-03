#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//random_device rd;
//uniform_int_distribution<int> nn(2, 300);
//uniform_int_distribution<int> dist(0, 1000000000);
//      chrono::system_clock::now();
//      chrono::duration_cast<chrono::milliseconds>(finish - start).count()

const ld eps = 1e-10;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i){
        for(int j = i + 1; j < s.length(); ++j){
            for(int k = j + 1; k < s.length(); ++k){
                int val = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if(val % 8 == 0){
                    cout << "YES" << endl;
                    cout << val << endl;
                    return 0;
                }
            }
        }
    }
    for(int j = 0; j < s.length(); ++j){
        for(int k = j + 1; k < s.length(); ++k){
            int val = (s[j] - '0') * 10 + (s[k] - '0');
            if(val % 8 == 0){
                cout << "YES" << endl;
                cout << val << endl;
                return 0;
            }
        }
    }
    for(int k = 0; k < s.length(); ++k){
        int val = (s[k] - '0');
        if(val % 8 == 0){
            cout << "YES" << endl;
            cout << val << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}