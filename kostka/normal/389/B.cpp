#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

char tab[107][107];
int nr[107][107], nrr;
int dx[] = {0,1,0,0,-1}, dy[] = {0,0,1,-1,0};

void krzyz(int a, int b)
{
    if(a==0 || b==0)
        return;
    for(int i=0; i<5; i++)
        if(tab[a+dx[i]][b+dy[i]]!='#' || nr[a+dx[i]][b+dy[i]] != 0)
            return;
    ++nrr;
    for(int i=0; i<5; i++)
        nr[a+dx[i]][b+dy[i]] = nrr;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> tab[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            krzyz(i,j);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(tab[i][j]=='#' && nr[i][j]==0)
            {
                puts("NO");
                return 0;
            }
    puts("YES");
    return 0;
}