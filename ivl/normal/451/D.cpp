#include <cstdio>
#include <vector>

using namespace std;

char in[100005];
int len;

vector < int > v;

int main(){
    scanf("%s", in);
    while (in[len] != '\0') ++len;
    for (int i = 0, j = 0; i < len; i = j){
        while (j < len && in[j] == in[i]) ++j;
        v.push_back(j - i);
        //printf("%d\n", j - i);
    }
    long long r1 = 0, r2 = 0; // r1 neparni, r2 parni
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0; // a neparan, b paran
    int csum = 0;
    for (int i = 0; i < v.size(); ++i){
        //printf(" - %I64d %I64d\n", r2, r1);
        //printf(" %d %d %d %d\n", a1, b1, a2, b2);
        int x = v[i];
        if (i & 1){
           //if (x & 1) swap(a2, b2);
           for (int t = 1 + csum; t <= x + csum; ++t){
               if (t & 1){
                  ++a1;
                  r1 += a1;
                  r2 += b1;
               }
               else {
                    ++b1;
                    r1 += b1;
                    r2 += a1;
               }
           }
        }
        else {
             
           //if (x & 1) swap(a1, b1);
           for (int t = 1 + csum; t <= x + csum; ++t){
               if (t & 1){
                  ++a2;
                  r1 += a2;
                  r2 += b2;
               }
               else {
                    ++b2;
                    r1 += b2;
                    r2 += a2;
               }
           }
        }
        csum += x;
    }
    printf("%I64d %I64d\n", r2, r1);
    return 0;
}