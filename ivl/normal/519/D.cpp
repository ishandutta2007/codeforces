#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int V[26];
char in[100005];
long long p[100005];
int n;
long long P(int a){if (a < 0) return 0; return p[a];}

vector < int > v[26];
map < long long, int > M;

int main(){
    for (int i = 0; i < 26; ++i) scanf("%d", V + i);
    scanf("%s", in);
    n = strlen(in);
    for (int i = 0; i < n; ++i) p[i] = V[in[i] - 'a'];
    for (int i = 0; i < n; ++i) p[i + 1] += p[i];
    for (int i = 0; i < n; ++i) v[in[i] - 'a'].push_back(i);
    long long R = 0;
    for (int x = 0; x < 26; ++x){
        M.clear();
        for (int i = 0; i < v[x].size(); ++i){ 
            long long X = P(v[x][i] - 1), Y = P(v[x][i]);
            R += M[X];
            ++M[Y];
        }
    }
    printf("%I64d\n", R);
    return 0;
}