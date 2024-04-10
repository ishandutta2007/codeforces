#include<bits/stdc++.h>
using namespace std;

int get(){
    int x;
    string s;
    cin >> x;
    for(int i = 1 ; i <= x ; ++i) cin >> s;
    return x;
}

int main(){
    do{
        puts("next 0 1");
        get();
        puts("next 1");
    }while(get() > 2);
    do{
        puts("next 0 1 2 3 4 5 6 7 8 9");
    }while(get() > 1);
    puts("done");
    return 0;
}