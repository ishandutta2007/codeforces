#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

int t;
char in[20];

int main(){
    scanf("%d", &t);
    for (int i = 0; i < t; ++i){
        scanf("%s", in);
        vector < pair < int, int > > v;
        for (int a = 1; a <= 12; ++a){
            if (12 % a != 0) continue;
            int b = 12 / a;
            bool check = false;
            for (int j = 0; j < b; ++j){
                bool c2 = true;
                for (int k = 0; k < a; ++k) if (in[k * b + j] == 'O') c2 = false;
                if (c2){check = true; break;}
            }
            if (check) v.push_back(make_pair(a, b));
        }
        printf("%d ", v.size());
        for (int j = 0; j < v.size(); ++j) printf("%dx%d ", v[j].x, v[j].y);
        printf("\n");
    }
    return 0;
}