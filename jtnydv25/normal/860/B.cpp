#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int N = 7e4 + 10;

bool impossible[10][10][N];
int pw10[10], a[N];
set<int> there[10];
string s;
string answer[N];
int ans[N];
int main(){

    int n;
    sd(n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s = to_string(a[i]);
        for(int j = 0; j < 9; j++){
            int val = 0;
            for(int k = j; k < 9; k++){
                val = val * 10 + s[k] - '0';
                if(there[k - j + 1].count(val)) impossible[j][k][i] = 1;
            }
        }

        for(int j = 0; j < 9; j++){
            int val = 0;
            for(int k = j; k < 9; k++){
                val = val * 10 + s[k] - '0';
                there[k - j + 1].insert(val);
            }
        }
        // cerr << impossible[1][3][2] << endl;
        ans[i] =1000000;
    }   

    for(int i = 0; i < 10; i++) there[i].clear();

    for(int i = n; i >= 1; i--){
        s = to_string(a[i]);
        for(int j = 0; j < 9; j++){
            int val = 0;
            for(int k = j; k < 9; k++){
                val = val * 10 + s[k] - '0';
                // if(i == 3 && k - j + 1 == 3) cerr << val << endl;
                if(there[k - j + 1].count(val)) impossible[j][k][i] = 1;
            }
        }

        for(int j = 0; j < 9; j++){
            int val = 0;
            for(int k = j; k < 9; k++){
                val = val * 10 + s[k] - '0';
                there[k - j + 1].insert(val);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        s = to_string(a[i]);
        for(int j = 0; j < 9; j++){

            for(int k = j; k < 9; k++){
                if(!impossible[j][k][i]){
                   if(k - j + 1 < ans[i]){
                        ans[i] = k - j + 1;
                        answer[i] = s.substr(j, k - j + 1);
                   }
                }
            }
        }
    }
    // cerr << impossible[1][3][2] << endl; 
    for(int i = 1; i <= n; i++){
        // puts(answer[i]);
        printf("%s\n", answer[i].c_str());
        // cout << answer[i] << "\n";
    }
}