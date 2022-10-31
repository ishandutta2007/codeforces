#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[101], b[101];

bool automaton() {
    int i = 0, j = 0;
    while(a[i] && b[j]) {
        if(a[i] == b[j])
            i++, j++;
        else
            i++;
    }
    return !b[j];
}

bool array1() {
    sort(a, strchr(a, '\0'));
    sort(b, strchr(b, '\0'));
    return !strcmp(a, b);
}

int main(){
    scanf("%s %s", a, b);
    if(automaton())
        puts("automaton");
    else if(array1())
        puts("array");
    else if(automaton())
        puts("both");
    else
        puts("need tree");
}