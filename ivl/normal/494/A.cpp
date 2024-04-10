#include <cstdio>
#include <vector>

using namespace std;

char in[100005];
int l;

int main(){
    scanf("%s", in); while (in[l] != '\0') ++l;
    int cnt = 0; vector < int > sol; int last = 0;
    for (int i = 0; i < l; ++i){
        if (in[i] == '(') ++cnt;
        if (in[i] == ')') --cnt;
        if (in[i] == '#'){--cnt; sol.push_back(1); in[i] = ')'; last = i;}
        if (cnt < 0){printf("-1\n"); return 0;}
    }
    sol.back() += cnt;
    cnt = 0;
    for (int i = 0; i < l; ++i){
        if (in[i] == '(') ++cnt;
        if (in[i] == ')') --cnt;
        if (i == last) cnt -= sol.back() - 1;
        if (cnt < 0){printf("-1\n"); return 0;}
    }
    for (int i = 0; i < sol.size(); ++i) printf("%d\n", sol[i]);
    return 0;
}