#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 200005;

char s[N], t[N];
int has[N][10];

void slv(){
    int n;
    cin >> n >> s;
    for(int t = 0; t <= 9; t++){
        has[n][t] = 0;
        for(int i = n - 1; i >= 0; i--) has[i][t] = has[i + 1][t] || (s[i] == t + '0');
    }
    int i = 0;
    char mi = *min_element(s, s + n);
    while(s[i] != mi) i++;
    fill(t, t + n, '2');
    t[n] = 0;
    for(; i < n; ){
        t[i] = '1';
        int j;
        for(j = s[i] - '0'; j <= 9; j++) if(has[i + 1][j]) break;
        if(j > 9) break;
        i++;
        while(s[i] != j + '0') i++;
    }
    for(int i = 0; i < n; i++) if(t[i] == '2'){ mi = s[i]; break; }
    for(int i = 0; i < n; i++) if(t[i] == '1' && s[i] > mi){
        for(; i < n; i++) t[i] = '2';
        break;
    }
    vector<char> v;
    for(int i = 0; i < n; i++) if(t[i] == '1') v.push_back(s[i]);
    for(int i = 0; i < n; i++) if(t[i] == '2') v.push_back(s[i]);
    for(int i = 1; i < n; i++) if(v[i - 1] > v[i]){ cout << "-\n"; return; }
    cout << t << '\n';
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--) slv();
}