/**
 * This line was copied from template
 * This is nk_ok.cpp
 * 
 * @author: Nikolay Kalinin
 * @date: Tue, 24 Apr 2018 19:13:31 +0300
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

struct tnode
{
    tnode *go[26];
    bool term;
    
    tnode()
    {
        for (int i = 0; i < 26; i++) go[i] = NULL;
        term = false;
    }
};

using pnode = tnode*;

pnode root;
char s[100005];
int n;

void add()
{
    pnode cur = root;
    char *t = s;
    while (*t != '\0')
    {
        if (cur->go[*t - 'a'] == NULL) cur->go[*t - 'a'] = new tnode();
        cur = cur->go[*t - 'a'];
        t++;
    }
    cur->term = true;
}

using tans = multiset<int>;
using pans = tans*;

pans merge(pans a, pans b)
{
    if (a->size() > b->size()) swap(a, b);
    for (auto t : *a) b->insert(t);
    delete a;
    return b;
}

pans calc(pnode cur, int curd)
{
    pans ans = new tans;
    for (int i = 0; i < 26; i++) if (cur->go[i] != NULL)
    {
        auto t = calc(cur->go[i], curd + 1);
        ans = merge(ans, t);
    }
    if (cur->term) ans->insert(curd);
    else if (curd != 0)
    {
        ans->erase(prev(ans->end()));
        ans->insert(curd);
    }
    return ans;
}

int main()
{
    root = new tnode();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        add();
    }
    auto ans = calc(root, 0);
//     for (auto t : *ans) cout << t << ' ';
//     cout << endl;
    cout << accumulate(all(*ans), 0) << endl;
    return 0;
}