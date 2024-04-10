#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool b[53][2];
    for (int i = 0; i < 53; i++){
        b[i][0] = false;
        b[i][1] = false;
    }
    int otv[53];
    int a, c;
    int kol = 0;
    for (int i = 0; i < (n * n); i++){
        cin >> a >> c;
        if ((b[a][0] == false) && (b[c][1] == false)){
            otv[kol] = i + 1;
            kol++;
            b[a][0] = true;
            b[c][1] = true;
        }
    }
    for (int i = 0; i < (kol); i++){
     cout << otv[i] << ' ';
    }
    return 0;
}