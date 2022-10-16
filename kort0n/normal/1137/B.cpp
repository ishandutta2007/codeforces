#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
//#define PI (acos-1))
string S;
string T;
int A[500100];
int main() {
    //cout.precision(10);
    cin >> S >> T;
    A[0] = T.size();
    {
    int i = 1, j = 0;
    while (i < T.size()) {
      while (i+j < T.size() && T[j] == T[i+j]) ++j;
      A[i] = j;
      if (j == 0) { ++i; continue;}
      int k = 1;
      while (i+k < T.size() && k+A[k] < j) A[i+k] = A[k], ++k;
      i += k; j -= k;
    }
    }
    for(int i = 0; i < T.size(); i++) {
        //cout << i << " " << A[i] << endl;
    }
    int zeroS = 0;
    int oneS = 0;
    int zeroT = 0;
    int oneT = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '0') zeroS++;
        else oneS++;
    }
    for(int i = 0; i < T.size(); i++) {
        if(T[i] == '0') zeroT++;
        else oneT++;
    }
    if(zeroS < zeroT || oneS < oneT) {
        cout << S << endl;
        return 0;
    }
    int start_index = 1;
    while(true) {
        if(A[start_index] + start_index == T.size()) break;
        start_index++;
    }
    //cout << start_index << A[start_index] << endl;
    int zeroLeading = 0;
    int oneLeading = 0;
    for(int i = T.size() - start_index; i < T.size(); i++) {
        if(T[i] == '0') zeroLeading++;
        else oneLeading++;
    }
    zeroS -= zeroT;
    oneS -= oneT;
    int leading = 1e9;
    if(zeroLeading != 0) leading = min(leading, zeroS / zeroLeading);
    if(oneLeading != 0) leading = min(leading, oneS / oneLeading);
    string LEADING = T.substr(T.size() - start_index, start_index);
    cout << T;
    for(int i = 0; i < leading; i++) cout << LEADING;
    for(int i = 0; i < zeroS - leading * zeroLeading; i++) cout << "0";
    for(int i = 0; i < oneS - leading * oneLeading; i++) cout << "1";
    cout << endl;
    /*
    int ans = 1e9;
    if(zeroT != 0) ans = min(ans, zeroS / zeroT);
    if(oneT != 0) ans = min(ans, oneS / oneT);
    int zero = zeroS - zeroT * ans;
    int one = oneS - oneT * ans;
    for(int i = 0; i < ans; i++) cout << T;
    for(int i = 0; i < zero; i++) cout << "0";
    for(int i = 0; i < one; i++) cout << "1";
    cout << endl;
    */
    return 0;
}