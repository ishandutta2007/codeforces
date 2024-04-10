#include <cstdio>
#include <cstdlib>
#include <set>
#define x first
#define y second

using namespace std;

void imp(){printf("Impossible\n"); exit(0);}

int n;
char in[105][105];
int l[105];

#define less ne_zajebavaj

bool zajeb = false;
bool less[35][35];
void check(char *a, char *b){
     if (*a == '\0' || *b == '\0'){zajeb |= (*b == '\0' && *a != '\0'); return;}
     if (*a == *b){check(a + 1, b + 1); return;}
     less[*a - 'a'][*b - 'a'] = true;
}

int bio[35];
bool dfs(int p){
     if (bio[p] == 1) return true;
     if (bio[p] == 2) return false;
     bio[p] = 1;
     for (int i = 0; i < 26; ++i) if (less[p][i]) if (dfs(i)) return true;
     bio[p] = 2;
     return false;
}

int inD[35];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%s", in[i]);
        while (in[i][l[i]] != '\0') ++l[i];
    }
    for (int i = 1; i < n; ++i) check(in[i - 1], in[i]);
    if (zajeb) imp();
    
    for (int i = 0; i < 26; ++i) if (dfs(i)) imp();
    for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) if (less[i][j]) ++inD[j];
    
    set < pair < int, int > > S;
    for (int i = 0; i < 26; ++i) S.insert(make_pair(inD[i], i));
    
    while (!S.empty()){
          int x = S.begin()->y; S.erase(S.begin());
          printf("%c", (char)(x + 'a'));
          for (int i = 0; i < 26; ++i){
              if (!less[x][i]) continue;
              S.erase(make_pair(inD[i], i));
              --inD[i];
              S.insert(make_pair(inD[i], i));
          }
    }
    printf("\n");
    
    return 0;
}