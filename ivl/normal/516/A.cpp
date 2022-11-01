#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char in[1005];

vector < int > out;

int main(){
    scanf("%d%s", &n, in);
    for (int i = 0; i < n; ++i){
        int x = in[i] - '0';
        if (x == 0 || x == 1) continue;
        if (x == 2 || x == 3 || x == 5 || x == 7) out.push_back(x);
        if (x == 4){
           out.push_back(3);
           out.push_back(2);
           out.push_back(2);
        }
        if (x == 6){
           out.push_back(5);
           out.push_back(3);
        }
        if (x == 8){
           out.push_back(7);
           out.push_back(2);
           out.push_back(2);
           out.push_back(2);
        }
        if (x == 9){
           out.push_back(7);
           out.push_back(3);
           out.push_back(3);
           out.push_back(2);
        }
    }
    sort(out.begin(), out.end()); reverse(out.begin(), out.end());
    for (int i = 0; i < out.size(); ++i) printf("%d", out[i]); printf("\n");
    return 0;
}