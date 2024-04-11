#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>

using namespace std;

queue <pair <int, int> > Q;

char tab[507][507];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; i++)
        scanf("%s", tab[i]);
    bool czy = true;
    int ile = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(tab[i][j]=='.')
            {
                ile++;
                if(czy)
                {
                    czy = false;
                    Q.push(make_pair(i,j));
                    tab[i][j] = '!';
                }
            }
    //printf("%d\n", ile);
    ile -= k+1;
    while(!Q.empty())
    {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        if(ile==0)
            break;
        for(int i=0; i<4; i++)
            if(x+dx[i]>=0 && y+dy[i]>=0 && tab[x+dx[i]][y+dy[i]]=='.')
            {
                if(ile--)
                    tab[x+dx[i]][y+dy[i]] = '!';
                if(ile==0)
                    break;
                Q.push(make_pair(x+dx[i], y+dy[i]));
            }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(tab[i][j]=='.')
                printf("X");
            else if(tab[i][j]=='!')
                printf(".");
            else 
                printf("%c", tab[i][j]);
        printf("\n");
    }
    return 0;
}