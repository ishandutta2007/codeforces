#include <cstdio>

using namespace std;

char value[105], rez[200], *it1, *it2;
int n, len;
bool neg;

int main(){
    scanf("%s", value);
    for (; value[n]; ++n);
    for (; value[len] != '.' && value[len] != 0; ++len);
    neg = (value[0] == '-');
    it1 = value;
    it2 = rez;
    if (neg){
        *it2 = '(';
        ++it2;
        ++it1;
        --n;
        --len;
    }
    *it2 = '$';
    ++it2;
    for (int i = 0; i < len; ++i){
        if (((len - i) % 3) == 0 && i != 0 && (len - i - 1) != 0){
            *it2 = ',';
            ++it2;
        }
        *it2 = *it1;
        ++it2;
        ++it1;
    }
    *it2 = '.';
    ++it2;
    ++it1;
    if (*it1 == 0){
        *it1 += '0';
    }
    *it2 = *it1;
    ++it2;
    ++it1;
    if (*it1 == 0){
        *it1 += '0';
    }
    *it2 = *it1;
    ++it2;
    ++it1;
    if (neg){
        *it2 = ')';
    }
    printf("%s\n", rez);
    return 0;
}