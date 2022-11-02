#include <iostream>
using namespace std;

int o[2009], t[2009], a[2009], m[2009][2009];

int main()
{
    int n, mx;
    cin>>n;
    o[n+1] = 0; t[0] = 0;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        if (a[i] == 2) t[i] = t[i-1] + 1;
        else t[i] = t[i-1];
    }
    for (int i = n; i >= 1; i--){
        if (a[i] == 1) o[i] = o[i+1] + 1;
        else o[i] = o[i+1];
    }
    for (int i = n; i >= 1; i--){
        for (int j = i; j >= 1; j--){
            if (i == j){
                m[i][j] = 1;
                continue;
            }
            if (a[j] == 1)
                m[i][j] = max(m[i][j+1], o[j] - o[i+1]);
            else
                m[i][j] = m[i][j+1] + 1;
        }
    }
    o[0] = 0; t[n+1] = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == 1) o[i] = o[i-1] + 1;
        else o[i] = o[i-1];
    }
    for (int i = n; i >= 1; i--){
        if (a[i] == 2) t[i] = t[i+1] + 1;
        else t[i] = t[i+1];
    }
    mx = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int r = o[i-1] + m[j][i] + t[j+1];
            if (mx < r)
                mx = r;
        }
    }
    cout<<mx<<'\n';
    return 0;
}