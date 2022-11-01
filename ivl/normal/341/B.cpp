#include <cstdio>
#include <set>
#include <utility>
#define x first
#define y second
using namespace std;

int n;
int in[100005];

set < pair < int, int > > S;
set < pair < int, int > >::iterator it;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", in + i);
    S.insert(make_pair(0, 0));
    for (int i = 0; i < n; ++i){
        S.insert(make_pair(in[i], 0));
        it = S.find(make_pair(in[i], 0));
        --it;
        int a = (*it).y;
        ++a;
        ++it;
        S.erase(it);
        S.insert(make_pair(in[i], a));
        it = S.find(make_pair(in[i], a));
        ++it;
        while (it != S.end()){
              if ((*it).y <= a){
                 S.erase(it);
                 it = S.find(make_pair(in[i], a));
                 ++it;
                 continue;
              }
              break;
        }
    }
    int rez = 0;
    for (it = S.begin(); it != S.end(); ++it){
        rez = max(rez, (*it).y);
    }
    printf("%d\n", rez);
    return 0;
}