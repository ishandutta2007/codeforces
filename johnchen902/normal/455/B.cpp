#include <cstdio>
using namespace std;
struct Trie {
    Trie * child[26];
    void build(char * s);
    bool win() const;
    bool lose() const;
};
void Trie::build(char * s) {
    if(!*s) return;
    if(!child[*s - 'a'])
        child[*s - 'a'] = new Trie();
    child[*s - 'a']->build(s + 1);
}
bool Trie::win() const {
    bool winning = false;
    for(Trie * t : child)
        if(t)
            winning = winning || !t->win();
    return winning;
}
bool Trie::lose() const {
    bool any = false;
    for(Trie * t : child)
        if(t)
            any = true;
    if(!any)
        return true;
    bool losing = false;
    for(Trie * t : child)
        if(t)
            losing = losing || !t->lose();
    return losing;
}

char s[100001];
Trie t;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        t.build(s);
    }
    bool w = t.win(), l = t.lose();
    if(w && l) {
        puts("First");
    } else {
        puts((w && (k % 2)) ? "First" : "Second");
    }
}