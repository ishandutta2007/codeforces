#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    while(isdigit(c)){
        a = (a << 3) + (a << 1) + (c ^ '0');
        c = getchar();
    }
    return f ? -a : a;
}

inline int poww(long long a , int b , int p){
    int times = 1;
    while(b){
        if(b & 1)
            times = times * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return times;
}

int main(){
    int a = read();
    if(a == 1)
        printf("YES\n1");
    else
        if(a == 4)
            printf("YES\n1\n3\n2\n4");
        else{
            bool f = 0;
            for(int i = 2 ; i * i <= a && !f ; ++i)
                f = a % i == 0;
            if(!f){
                printf("YES\n1");
                for(int i = 2 ; i < a ; ++i)
                    printf("\n%lld" , poww(i - 1 , a - 2 , a) * 1ll * i % a);
                printf("\n%d" , a);
            }
            else
                puts("NO");
        }
    return 0;
}