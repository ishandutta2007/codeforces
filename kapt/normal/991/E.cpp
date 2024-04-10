#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int permutations(string s){
    int n = s.size();
    set <char> ws;
    map <char, int> countw;
    vector <char> wv;
    for (int i = 0; i < n; ++i){
        if (!ws.count(s[i])){
            ws.insert(s[i]);
            wv.push_back(s[i]);
        }
        countw[s[i]]++;
    }
    int facts[20] = {1};
    for (int i = 1; i <= n; ++i){
        facts[i] = facts[i - 1] * i;
    }
    int ans = facts[n];
    for (auto elem : wv){
        ans /= facts[countw[elem]];
    }
    return ans;
}

string str(int x){
    ostringstream temp;
    temp << x;
    string sl = temp.str();
    return sl;
}

int ans = 0;
int arr[10], countnum[10];

void solve(int x){
    // cout << x << endl;
    if (x == 10){
        for (int i = 0; i < 10; ++i){
            // cout << arr[i] << " ";
        }
        // cout << endl;
        int nowans;
        string num = "";
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < arr[i]; ++j){
                num = num + str(i);
            }
        }
        // cout << 1 << endl;
        // cout << num << endl;
        nowans = permutations(num);
        // cout << nowans << endl;
        if (arr[0] != 0){
            arr[0]--;
            num = "";
            for (int i = 0; i < 10; ++i){
                for (int j = 0; j < arr[i]; ++j){
                    num = num + str(i);
                }
            }
            nowans -= permutations(num);
            arr[0]++;
        }
        // cout << nowans << "   0" << endl;
        ans += nowans;
        return;
    }
    for (int i = 0; i <= countnum[x]; ++i){
        if (countnum[x] > 0 && i == 0){
            continue;
        }
        if (x == 0){
            // cout << i << "5757575757\n";
        }
        arr[x] = i;
        solve(x + 1);
    }
}

main(){
    for (int i = 0; i < 10; ++i){
        arr[i] = 0;
    }
    string n;
    cin >> n;
    for (auto ch : n){
        countnum[ch - '0']++;
    }
    // cout << countnum[0] << endl;
    solve(0);
    cout << ans;
    return 0;
}