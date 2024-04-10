#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n, x = 0, y = 0, i;
    char s1[21];
    char s2[21];
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n = strlen(s1);
    
    for (i = 0; i < n; i += 2) {
        if (s1[i] == s2[i]) continue;
        
        if (s1[i] == '8') {
            if (s2[i] == '[') {
                x++;
            } else {
                y++;
            }
        } else if (s1[i] == '[') {
            if (s2[i] == '(') {
                x++;
            } else {
                y++;
            }
        } else {
            if (s2[i] == '8') {
                x++;
            } else {
                y++;
            }
        }
    }
    
    if (x > y) {
        puts("TEAM 1 WINS");
    } else if (x == y) {
        puts("TIE");
    } else {
        puts("TEAM 2 WINS");
    }
    
    return 0;
}