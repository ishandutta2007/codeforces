#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
    node* next[26];
    bool end;
    int pobednik,misere;
};

node Trie[100005];
char S[100005];
node *root,*last;
int K;

void ucitaj(){
    root = Trie;
    last = Trie;
    node* curr;
    int n,i,j,l;
    scanf("%d%d",&n,&K);
    for (i=1; i<=n; i++){
        scanf("%s",S+1);
        l = strlen(S+1);
        curr = root;
        for (j=1; j<=l; j++){
            if (curr->next[S[j]-'a'] != NULL){
                curr = curr->next[S[j]-'a'];
            } else {
                last++;
                curr->next[S[j]-'a'] = last;
                curr = last;
            }
        }
        curr->end = true;
    }
}

void resi(node *curr){
    int i;
    curr->pobednik = 2;
    curr->misere = 2;
    bool imapotez = false;
    for (i=0; i<26; i++){
        if (curr->next[i] != NULL){
            resi(curr->next[i]);
            imapotez = true;
            if (curr->next[i]->pobednik == 2){
                curr->pobednik = 1;
            }
            if (curr->next[i]->misere == 2){
                curr->misere = 1;
            }
        }
    }
    if (!imapotez) curr->misere = 1;
}

int main(){
    ucitaj();
    resi(root);
    bool misere,std,prvi;
    misere=std=prvi=false;

    misere = root->misere == 1;
    std = root->pobednik == 1;

    if (misere && std) prvi = true;
    if (!misere && !std) prvi = false;
    if (!misere && std){
        prvi = K%2 == 1;
    }
    if (misere && !std){
        prvi = false;
    }
    if (prvi) printf("First\n"); else printf("Second\n");
    return 0;
}