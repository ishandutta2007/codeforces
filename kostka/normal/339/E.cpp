/*/
   Rozwiazanie wzorcowe zadania Tasiemka
   Autor: Bartek Kostka
/*/

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
static int tab[MAXN], sab[MAXN], snr[MAXN];
static bool swa[MAXN];
vector <pair <int, int> > Q, S, V;

bool check(int n)
{
    V.clear();
    for(int p=0; p<n; p++)
        V.push_back(make_pair(snr[p],sab[p]));
    sort(V.begin(), V.end());
    for(int p=1; p<n; p++)
    {
        if(V[p].second < V[p-1].second)
            return false;
    }
    return true;    
}

void print()
{
    printf("%d\n", (int)Q.size());
    for(int i=(int)Q.size()-1; i>=0; i--)
        printf("%d %d\n", Q[i].first, Q[i].second);
}

bool dfs(int x, int n, int k)
{   
    if(check(n))
        return true;
    if(x==k)
        return false;   
    for(int i=1; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(swa[i]==0 || swa[j]==0)
                continue;
            int a = snr[i], b = snr[j];
            if(a>b)
                swap(a,b);
            Q.push_back(make_pair(a,b));
            for(int p=0; p<n; p++)
                if(a <= snr[p] && snr[p] <= b)
                    snr[p] = b-snr[p]+a;                
            if(dfs(x+1,n,k))
                return true;
            for(int p=0; p<n; p++)
                if(a <= snr[p] && snr[p] <= b)
                    snr[p] = b-snr[p]+a;
            Q.pop_back();
        }
    return false;   
}

bool czy[MAXN];

int main()
{
    int n, k;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        if(czy[tab[i]]==1)
        {
            puts("NIE");
            return 0;
        }
        czy[tab[i]] = 1;
    }

    // mamy straznikow: tab[0] = 0 oraz tab[n+1] = n+1
    tab[0] = 0;
    tab[n+1] = n+1;

    int si = 0;
    for(int i=0; i<=n+1; i++)
    {
        //printf("%d\n", tab[i]);
        if((si==0) || (tab[i] != sab[si-1]))
        {
            sab[si] = tab[i];
            snr[si] = i;
            swa[si++] = 1;
        }
        if(tab[i]<tab[i+1])
        {
            while(tab[i]==tab[i+1]-1)
                i++;
            int m = (tab[i]+sab[si-1])/2;
            int mm = (i+snr[si-1])/2;
            if(m != sab[si-1])
            {
                sab[si] = m;
                snr[si++] = mm;
            }           
            if(tab[i] != sab[si-1])
            {
                sab[si] = tab[i];
                snr[si] = i;
                swa[si++] = 1;
            }
            else
            {
                snr[si-1] = i;
                swa[si-1] = 1;
            }
        }
        else
        {
            while(tab[i]==tab[i+1]+1)
                i++;
            int m = (tab[i]+sab[si-1])/2;
            int mm = (i+snr[si-1])/2;           
            if(m != sab[si-1])
            {
                sab[si] = m;
                snr[si++] = mm;
            }                       
            if(tab[i] != sab[si-1])
            {
                sab[si] = tab[i];
                snr[si] = i;
                swa[si++] = 1;
            }
            else
            {
                snr[si-1] = i;
                swa[si-1] = 1;
            }
        }
    }
    if(si>21)
    {
        puts("NIE");
        return 0;
    }
    if(dfs(0,si,3))
    {
        print();
    }
    else
        puts("NO");
    return 0;
}