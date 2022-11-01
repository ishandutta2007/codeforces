#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;

char str[2000000];

int main(void) {
    scanf("%s", str);
    int n = strlen(str);
    deque<int> result;
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == 'r') {
            result.push_front(i + 1);
        } else
            result.push_back(i + 1);
    }
    for (auto it = result.begin(); it != result.end(); ++it)
        printf("%d\n", *it);
    return 0;
}