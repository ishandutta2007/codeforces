#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int maxn = 200;
const int inf = 1e9;

list<pair<int, int> > st;
pair<int, int> index[maxn];
int b, f, n, l;

void init()
{
    st.pb(mp(-inf, -b));
    st.pb(mp(l + f, inf));
    st.pb(mp(l + f, inf));
};
void scan()
{
    cin >> l >> b >> f >> n;
};
void remove(int w)
{
    st.erase(find(st.begin(), st.end(), index[w]));
};
int implace(int w, int i)
{
    int spos, epos;
    for (list<pair<int, int> > :: iterator it = st.begin(); it != st.end();)
    {
        spos = it->second + b;
        it++;
        epos = it->first - f;
        if (0 <= spos && spos <= l && epos - spos >= w)
        {
            st.insert(it, mp(spos, spos + w));
            index[i] = mp(spos, spos + w);
            return spos;
        }
        else if (spos > l)
            return -1;
    }
    return -1;
};

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scan();
    init();
    int t, w;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> w;
        if (t == 1)
            cout << implace(w, i) << endl;
        else if (t == 2)
            remove(w - 1);
    }
    return 0;
}