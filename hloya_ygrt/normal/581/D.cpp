#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define ll long long
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>


const int maxn = 2e3+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

void bad(){ puts("-1"), exit(0); }
char a[maxn][maxn];
int t;

void answer()
{
    printf("%d\n", t);
    for (int i=0;i<t;i++){
        for (int j=0;j<t;j++){
            printf("%c",a[i][j]);
        }
        puts("");
    }
    exit(0);
}

void clean(char c)
{
    for (int i=0;i<t;i++)
    for (int j=0;j<t;j++){
        if (a[i][j] == c)
            a[i][j] = '.';
    }
}

bool put(int x, int y, char c, int sx, int sy){
    for (int i=sx; i < x + sx ; i++)
        for (int j = sy; j < y + sy ; j++){
            if (i >= t || j >= t){
                clean(c);
                return 0;
            }
            if (a[i][j] == '.'){
                a[i][j] = c;
            } else {
                clean(c);
                return 0;
            }
    }

    return 1;
}

int first_free(int x)
{
    for (int j=0;j<t;j++)
        if (a[x][j] == '.')
            return j;
    return -1;
}
void putc(char c, int x,int y)
{
    for (int i=0; i < t;i++){
            if (first_free(i) != -1){
                int posy = first_free(i);
                bool can = put(x, y, c, i, posy);
                if (!can)
                    can = put(y, x, c, i, posy);
                if (!can)
                    break;
                    answer();
                }
            }
}
int main()
{
    //files1;
    fast_io;
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1  >> y1 >>  x2 >> y2 >> x3 >> y3;
    int sq = x1 * y1 + x2 * y2 + x3 * y3;

    t = sqrt(sq);
    while (t * t > sq)
        t--;
    while (t * t < sq)
        t++;
    if ( t * t != sq ){
        bad();
    }

    clean((char)0);

    if (!put(x1, y1, 'A', 0, 0))
        bad();
    if (first_free(0) != -1){
        int posy = first_free(0);
        /*
            Try AB
                C
        */
        bool b = put(x2, y2, 'B', 0, posy);
        if (b)
            putc('C', x3, y3);
        clean('B');
        clean('C');

             b = put(y2, x2, 'B', 0, posy);
        if (b)
            putc('C', x3, y3);
        clean('B');
        clean('C');
        /*
            Try AC
                B
        */
        bool c = put(x3, y3, 'C', 0, posy);
        if (c)
            putc('B', x2, y2);
        clean('B');
        clean('C');

             c = put(y3, x3, 'C', 0, posy);
        if (c)
            putc('B', x2, y2);
        clean('B');
        clean('C');

        bad();
    } else
    {
        for (int i=0;i<t;i++){
            if (a[i][0] == '.'){
                bool b = put(x2, y2, 'B', i, 0);
                if (b)
                    putc('C', x3, y3 );
                clean('B');
                clean('C');
                     b = put(y2, x2, 'B', i, 0);
                if (b)
                    putc('C', x3, y3 );
                bad();
            }
        }
    }

    return 0;
}