#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXN = 100007;
static int tab[MAXN];
static priority_queue <pair <int, int> > X;
static vector <int> W;

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &tab[i]);
    sort(tab, tab + n);
    for(int i=0; i<n; i++)
    {
        int licz = 1;
        while(i+1<n && tab[i]==tab[i+1])
        {
            licz++;
            i++;
        }
        X.push(make_pair(licz, tab[i]));
    }
    while(X.size()>2)
    {
        vector <int> T;
        pair <int, int> a = X.top();
        X.pop();
        pair <int, int> b = X.top();
        X.pop();
        pair <int, int> c = X.top();
        X.pop();
        T.push_back(c.second);
        T.push_back(b.second);
        T.push_back(a.second);
        sort(T.begin(), T.end());
        W.push_back(T[2]);
        W.push_back(T[1]);
        W.push_back(T[0]);
        if(a.first > 1)
            X.push(make_pair(a.first-1, a.second));
        if(b.first > 1)
            X.push(make_pair(b.first-1, b.second));
        if(c.first > 1)
            X.push(make_pair(c.first-1, c.second));
    }
    int s = W.size()/3;
    printf("%d\n", s);
    for(int i=0; i<s; i++)
        printf("%d %d %d\n", W[3*i], W[3*i+1], W[3*i+2]);
    return 0;
}