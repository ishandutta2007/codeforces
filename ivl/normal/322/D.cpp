#include <cstdio>
#include <set>

using namespace std;

int n, m;

multiset < int > ATK;
multiset < int > DEF;
multiset < int > ciel;

char in[5];
int in2;

int g(){
    multiset < int >::iterator itt;
    for (multiset < int >::iterator it = DEF.begin(); it != DEF.end(); ++it){
        itt = ciel.upper_bound(*it);
        if (itt == ciel.end()) return 0;
        ciel.erase(itt);
    }
    int r = 0;
    for (multiset < int >::iterator it = ATK.begin(); it != ATK.end(); ++it){
        itt = ciel.lower_bound(*it);
        r += *itt - *it;
        if (itt == ciel.end()) return 0;
        ciel.erase(itt);
    }
    for (itt = ciel.begin(); itt != ciel.end(); ++itt) r += *itt;
    return r;
}

int f(int s){
    multiset < int > a, b;
    b = ciel;
    int r = 0;
    multiset < int >::iterator it = ATK.begin();
    for (int i = 0; i < s; ++i){
        a.insert(*it);
        r -= *it;
        ++it;
    }
    while (!a.empty()){
          it = a.end();
          --it;
          int x = *it;
          a.erase(it);
          it = b.end();
          if (it == b.begin()) return 0;
          --it;
          int y = *it;
          b.erase(it);
          r += y;
          if (y < x) return 0;
    }/*
    if (s == ATK.size()){
       for (multiset < int >::iterator it = DEF.begin(); it != DEF.end(); ++it){
           int x = *it;
           multiset < int >::iterator it2 = b.upper_bound(x);
           if (it2 == b.end()){
              return r;
           }
           b.erase(it2);
       }
    }
    if (s == ATK.size()) for (multiset < int >::iterator it = b.begin(); it != b.end(); ++it) r += *it;*/
    return r;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%s%d", in, &in2);
        if (in[0] == 'A') ATK.insert(in2);
        else DEF.insert(in2);
    }
    for (int i = 0; i < m; ++i){
        scanf("%d", &in2);
        ciel.insert(in2);
    }
    int r = 0;
    for (int i = 0; i <= ATK.size(); ++i) r = max(r, f(i));
    r = max(r, g());
    printf("%d\n", r);
    return 0;
}