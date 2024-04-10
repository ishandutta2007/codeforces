#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char data[9];
const char* names[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool ok(const char* name) {
    if(n != (int) strlen(name)) return false;
    for(int i = 0; i < n; i++)
        if(data[i] != '.' && data[i] != name[i])
            return false;
    return true;
}

int main(){
    scanf("%d%s", &n, data);
    for(int i = 0; i < 8; i++)
        if(ok(names[i]))
            puts(names[i]);
}