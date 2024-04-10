#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second


struct tnode
{
    tnode *go[26];
    int end;
    
    tnode()
    {
        for (int i = 0; i < 26; i++) go[i] = NULL;
        end = -1;
    }
};

typedef tnode* pnode;

const int maxlen = 1000006;

char s[maxlen], t[maxlen];
string str[maxlen];
int n, m;
bool can[maxlen];
pair<int, int> from[maxlen];

void add(pnode cur, char *x, int id)
{
    if (*x == '\0')
    {
        cur->end = id;
        return;
    }
    char c = *x;
    if (!(c>= 'a' && c <= 'z')) c += 'a' - 'A';
    if (cur->go[c - 'a'] == NULL) cur->go[c - 'a'] = new tnode;
    add(cur->go[c - 'a'], x + 1, id);
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    reverse(s, s  + n);
    scanf("%d", &m);
    pnode root = new tnode;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", t);
        str[i] = string(t);
        add(root, t, i);
    }
    can[0] = true;
    for (int i = 0; i < n; i++) if (can[i])
    {
//         cout << "here " << endl;
        pnode cur = root;
        for (int j = i; j < n; j++)
        {
//             cout << i << ' ' << j << ' ' << s[j] - 'a' << ' ' << cur->go[s[j] - 'a'] << endl;
            if (cur->go[s[j] - 'a'] == NULL) break;
            cur = cur->go[s[j] - 'a'];
//             cout << i << ' ' << j << ' ' << cur->end << endl;
            if (cur->end != -1)
            {
                can[j + 1] = true;
                from[j + 1] = {i, cur->end};
            }
        }
    }
    int cur = n;
    while (cur > 0)
    {
        printf("%s%c", str[from[cur].se].c_str(), " \n"[from[cur].fi == 0]);
        cur = from[cur].fi;
    }
    return 0;
}