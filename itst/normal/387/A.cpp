#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c)){
        a = (a << 3) + (a << 1) + (c ^ '0');
        c = getchar();
    }
    return a;
}

int main(){
    int s = read() * 60 + read() , t = read() * 60 + read();
    if(s < t)
        s += 24 * 60;
    s -= t;
    printf("%02d:%02d" , s / 60 , s % 60);
    return 0;
}