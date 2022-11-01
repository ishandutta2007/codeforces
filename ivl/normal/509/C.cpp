#include <cstdio>
#include <vector>

using namespace std;

#define string vector < char > 

string S;
bool bio[305][305][2];
string out;
bool dp(int pos, int cnt, bool ch){
     if (cnt < 0) return false;
     if (pos == S.size()) return (cnt == 0) && !ch;
     if (bio[pos][cnt][ch]++) return false;
     if (ch){
        for (int i = S[pos] - '0'; i <= 9; ++i){
            out.push_back(i + '0');
            if (dp(pos + 1, cnt - i, i == S[pos] - '0')) return true;
            out.pop_back();
        }
     }
     else {
          for (int i = 0; i <= 9; ++i){
              out.push_back(i + '0');
              if (dp(pos + 1, cnt - i, false)) return true;
              out.pop_back();
          }
     }
     return false;
}

string getS(const string &S, int b){
       ::S = S;
       out.clear();
       for (int i = 0; i <= 300; ++i)
           for (int j = 0; j <= 300; ++j)
               bio[i][j][0] = bio[i][j][1] = false;
       if (dp(0, b, true)) return out;
       int sz = max((int)S.size() + 1, (b + 8) / 9);

       string R(sz, '9');
       b -= 9 * sz;
       while (b < 0 && R[0] > '1') --R[0], ++b;
       for (int i = 1; i < sz; ++i){
           while (b < 0 && R[i] > '0') --R[i], ++b;
       }
       return R;
}

int n;
int b[305];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    
    string R;
    R.push_back('0');
    for (int i = 0; i < n; ++i){
        R = getS(R, b[i]);
        for (int i = 0; i < R.size(); ++i) printf("%c", R[i]); printf("\n");
    }
    return 0;
}