#include <cstdio>
#include <set>
#include <utility>
#define x first
#define y second

using namespace std;

int n;

set < pair < int, int > > S;

int out[100005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int a;
        scanf("%d", &a);
        if (a != 0){
           S.insert(make_pair(a, i));
           continue;
        }
        set < pair < int, int > > ::iterator it = S.end();
        int cnt = 0;
        while (it != S.begin()){
              --it;
              if (cnt < 3) out[(*it).y] = cnt; else out[(*it).y] = 3;
              ++cnt;
        }
        S.clear();
        if (cnt > 3) cnt = 3;
        out[i] = cnt + 15;
    }
    for (int i = 0; i < n; ++i){
        if (out[i] == 0) printf("pushStack\n");
        if (out[i] == 1) printf("pushQueue\n");
        if (out[i] == 2) printf("pushBack\n");
        if (out[i] == 3) printf("pushFront\n");
        if (out[i] >= 15){
           printf("%d", out[i] - 15);
           if (out[i] - 15 > 0) printf(" popStack");
           if (out[i] - 15 > 1) printf(" popQueue");
           if (out[i] - 15 > 2) printf(" popBack");
           printf("\n");
        }
    }
    return 0;
}