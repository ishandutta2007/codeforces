#include <iostream>
#include <cstdio>

using namespace std;

int n;
string s[100005];

string en;
int sz;
int poin;
bool sol = true;
void find(string x){
     for (int i = 0; i < x.size(); ++i){
         while (poin < sz && en[poin] != x[i]) ++poin;
         if (poin >= sz) sol = false;
         ++poin;
     }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    cin >> en;
    sz = en.size();
    for (int i = 0; i < n; ++i){
        find((string)"<3");
        find(s[i]);
    }
    find((string)"<3");
    if (sol) printf("yes\n");
    else printf("no\n");
    return 0;
}