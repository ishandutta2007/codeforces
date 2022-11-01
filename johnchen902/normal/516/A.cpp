#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const char* s[10] = {"", "", "2", "3", "322", "5", "53", "7", "7222", "7332"};

char ans[61];

int main(){
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        strcat(ans, s[c - '0']);
    }
    sort(ans, strchr(ans, '\0'), greater<char>());
    puts(ans);
}