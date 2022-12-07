#include <stdio.h>
#include <string.h>

const int N = 25;
char s1[N], s2[N];

int n1 = 0, n2 = 0;
int main() {
    scanf("%s%s", s1, s2);
    if (strlen(s1) != strlen(s2) || strlen(s1) % 2 || strlen(s2) % 2) {
        printf("TIE\n");
        return 0;
    }
    for (int i = 0; i < strlen(s1); i+=2) {
        if (s1[i] == '8' && s1[i + 1] == '<') {
            if (s2[i] == '[' &&  s2[i + 1] == ']')
                n1++;
            else if (s2[i] == '(' &&  s2[i + 1] == ')')
                n2++;
            else if (s2[i] == '8' &&  s2[i + 1] == '<') {
            }
            else {
                printf("TIE\n");
                return 0;
            }
        }
        else if (s1[i] == '[' && s1[i + 1] == ']') {
            if (s2[i] == '(' && s2[i + 1] == ')')
                n1++;
            else if (s2[i] == '8' &&  s2[i + 1] == '<')
                n2++;
            else if (s2[i] == '[' &&  s2[i + 1] == ']') {
            }
            else {
                printf("TIE\n");
                return 0;
            }
        }
        else if (s1[i] == '(' &&  s1[i + 1] == ')') {
            if (s2[i] == '8' &&  s2[i + 1] == '<')
                n1++;
            else if (s2[i] == '[' &&  s2[i + 1] == ']')
                n2++;
            else if (s2[i] == '(' &&  s2[i + 1] == ')') {
            }
            else {
                printf("TIE\n");
                return 0;
            }
        }
        else {
            printf("TIE\n");
            return 0;
        }
    }
    if (n1 > n2) printf("TEAM 1 WINS\n");
    else if (n1 < n2) printf("TEAM 2 WINS\n");
    else printf("TIE\n");
    return 0;
}