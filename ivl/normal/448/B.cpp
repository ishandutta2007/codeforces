#include <cstdio>

using namespace std;

char s[105], t[105];
int sl, tl;

bool automaton(){
     int p1 = 0;
     for (int i = 0; p1 < tl && i < sl; ++i){
         if (t[p1] == s[i]) ++p1;
     }
     if (p1 == tl) return true;
     return false;
}

bool array(){
     int num[100];
     for (int i = 0; i < 26; ++i) num[i] = 0;
     for (int i = 0; i < sl; ++i) ++num[s[i] - 'a'];
     for (int i = 0; i < tl; ++i) --num[t[i] - 'a'];
     for (int i = 0; i < 26; ++i) if (num[i] != 0) return false;
     return true;
}

bool both(){
     int num[100];
     for (int i = 0; i < 26; ++i) num[i] = 0;
     for (int i = 0; i < sl; ++i) ++num[s[i] - 'a'];
     for (int i = 0; i < tl; ++i) --num[t[i] - 'a'];
     for (int i = 0; i < 26; ++i) if (num[i] < 0) return false;
     return true;
}

int main(){
    scanf("%s%s", s, t);
    while (s[sl] != '\0') ++sl;
    while (t[tl] != '\0') ++tl;
    if (automaton()){printf("automaton\n"); return 0;}
    if (array()){printf("array\n"); return 0;}
    if (both()){printf("both\n"); return 0;}
    printf("need tree\n");
    return 0;
}