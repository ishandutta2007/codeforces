#include <cstdio>
#include <cstring>
#include <algorithm>

char s[101],t[101];
int lens, lent;
int x[26],y[26];
int strIn(){
    int piv = 0;
    for (int i=0; i<lens; i++) {
        if(t[piv]==s[i]){
            piv++;
        }
    }
    return piv == lent;
}

int strSame(){
    char ns[101],nt[101];
    memcpy(ns,s,lens);
    memcpy(nt,t,lent);
    std::sort(ns,ns+lens);
    std::sort(nt,nt+lent);
    for (int i=0; i<lens; i++) {
        if(ns[i] != nt[i]) return 0;
    }
    return 1;
}

int strSubset(){
    for (int i=0; i<lens; i++) {
        x[s[i]-'a']++;
    }
    for (int i=0; i<lent; i++) {
        y[t[i]-'a']++;
    }
    for (int i=0; i<26; i++) {
        if(x[i]<y[i]) return 0;
    }
    return 1;
}

int main(){
    scanf("%s %s",s,t);
    lens = (int)strlen(s);
    lent = (int)strlen(t);
    if(lens < lent){
        printf("need tree");
        return 0;
    }
    if(strIn()){
        printf("automaton");
        return 0;
    }
    if(lens==lent){
        if(strSame()){
            printf("array");
            return 0;
        }
    }
    printf(strSubset()?"both":"need tree");
}