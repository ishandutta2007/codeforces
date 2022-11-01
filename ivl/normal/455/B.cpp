#include <cstdio>

using namespace std;

class trie{
      public:
      trie *ch;
      int bm;
      bool b1, b2, bio; // b1 = pobjedit cu, b2 = izgubit cu
      trie(){
             bm = b1 = b2 = bio = 0;
             ch = 0;
      }
      bool get_b(int p){return ((bm >> p) & 1);}
      void set_b(int p){bm |= (1 << p);}
      void build(char *c, int len){
           if (len == 0) return;
           if (ch == 0) ch = new trie[26];
           set_b(c[0] - 'a');
           ch[c[0] - 'a'].build(c + 1, len - 1);
      }
      void dp(){
           if (bio++) return;
           if (bm == 0){b2 = true; return;}
           for (int i = 0; i < 26; ++i){
               if (!get_b(i)) continue;
               ch[i].dp();
               bool x = ch[i].b1, y = ch[i].b2;
               b1 |= !x;
               b2 |= !y;
           }
      }
} root;

int n, k;
char in[100005];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i){
        scanf("%s", in);
        int len = 0;
        while (in[len] != '\0') ++len;
        root.build(in, len);
    }
    root.dp();
    if (root.b1 && root.b2) printf("First\n");
    if (!root.b1 && root.b2) printf("Second\n");
    if (root.b1 && !root.b2){
       if (k & 1) printf("First\n");
       else printf("Second\n");
    }
    if (!root.b1 && !root.b2) printf("Second\n");
    return 0;
}