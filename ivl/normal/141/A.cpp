#include <cstdio>

using namespace std;

char host[105], guest[105], next[105];
int pon1[27], pon2[27];

int main(){
    scanf("%s%s%s", host, guest, next);
    for (int i = 0; host[i]; ++i){
        ++pon1[host[i] - 'A'];
    }
    for (int i = 0; guest[i]; ++i){
        ++pon1[guest[i] - 'A'];
    }
    for (int i = 0; next[i]; ++i){
        ++pon2[next[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i){
        if (pon1[i] != pon2[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}