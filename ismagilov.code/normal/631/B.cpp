#include <iostream>


using namespace std;

int main() {
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    int s[n][2];
    int st[m][2];
    for (int i = 0; i < n; i++){
        s[i][0] = 0;
        s[i][1] = -1;
    }
    for (int i = 0; i < m; i++){
        st[i][0] = 0;
        st[i][1] = -1;
    }
    for (int i = 0; i < k; i++){
        cin >> a >> b >> c;
        if (a == 1){
            s[b-1][0] = c;
            s[b-1][1] = i;
        }
        if (a == 2){
            st[b-1][0] = c;
            st[b-1][1] = i;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][1] > st[j][1]){
                cout << s[i][0] << ' ';
            }
            else{
                cout << st[j][0] << ' ';
            }
        }
        cout << endl;
    }
}