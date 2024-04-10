#include <cstdio>
#include <algorithm>

using namespace std;

char in[100005];
int l;

int main(){
    scanf("%s", in);
    while (in[l] != '\0') ++l;
    
    bool ch = true;
    for (int i = 0; i < l; ++i) if ((in[i] - '0') % 2 == 0) ch = false;
    if (ch){printf("-1\n"); return 0;}
    
    for (int i = 0; i < l; ++i){
        int x = in[i] - '0';
        if (x % 2) continue;
        if (x < in[l - 1] - '0'){
           swap(in[i], in[l - 1]);
           printf("%s\n", in);
           return 0;
        }
    }
    
    for (int i = l - 1; i >= 0; --i){
        int x = in[i] - '0';
        if (x % 2) continue;
        swap(in[i], in[l - 1]);
        printf("%s\n", in);
        return 0;
    }
    
    return 0;
}