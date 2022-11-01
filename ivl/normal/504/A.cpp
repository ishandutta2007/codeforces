#include <cstdio>
#include <set>
#include <vector>
#define x first
#define y second

using namespace std;

int n;
int deg[100005], s[100005];

vector < pair < int, int > > out;
set < pair < int, int > > S;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", deg + i, s + i);
        S.insert(make_pair(deg[i], i));
    }
    while (!S.empty()){
          pair < int, int > cr = *(S.begin());
          S.erase(S.begin());
          if (cr.x == 0) continue;
          out.push_back(make_pair(cr.y, s[cr.y]));
          S.erase(make_pair(deg[s[cr.y]], s[cr.y]));
          --deg[s[cr.y]];
          s[s[cr.y]] ^= cr.y;
          S.insert(make_pair(deg[s[cr.y]], s[cr.y]));
    }
    printf("%d\n", out.size());
    for (int i = 0; i < out.size(); ++i) printf("%d %d\n", out[i].x, out[i].y);
    return 0;
}