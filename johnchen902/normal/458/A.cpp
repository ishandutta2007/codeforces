#include <cstdio>
#include <cstring>
using namespace std;

char str1[100002];
char str2[100002];

void adj(char* str) {
    for(int i = 0; str[i + 2]; i++)
        for(int j = i; j >= 0; j -= 2)
            if(str[j] == '0' && str[j + 1] == '1' && str[j + 2] == '1')
                str[j] = '1', str[j + 1] = str[j + 2] = '0';
            else
                break;
}

int main(){
    scanf("%s %s", str1 + 1, str2 + 1);
    str1[0] = str2[0] = '0';
    adj(str1);
    adj(str2);
    char *p1 = strchr(str1, '1');
    char *p2 = strchr(str2, '1');
    auto cmp = [&](){
        if(!p1 && !p2)
            return 0;
        if(!p1) return -1;
        if(!p2) return 1;
        int l1 = strlen(p1);
        int l2 = strlen(p2);
        if(l1 != l2)
            return l1 - l2;
        return strcmp(p1, p2);
    };
    int i = cmp();
    if(i > 0) {
        puts(">");
    } else if(i == 0) {
        puts("=");
    } else {
        puts("<");
    }
}