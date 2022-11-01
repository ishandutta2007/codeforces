#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int T;
    for(cin >> T ; T ; --T){
        string s;
        cin >> s;
        sort(s.begin() , s.end());
        if(*s.begin() == *--s.end())
            puts("-1");
        else
            cout << s << endl;
    }
}