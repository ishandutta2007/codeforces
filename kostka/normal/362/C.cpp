#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 5007;
static int tab[MAXN];
static int mni[MAXN][MAXN], wie[MAXN][MAXN];

int main()
{
  int n, inw = 0;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &tab[i]);
  for(int i=0; i<n; i++)
  {
    int tmp1 = 0, tmp2 = 0;
    for(int j=0; j<n; j++)
    {
      if(tab[j]>i)
    tmp1++;
      if(tab[j]<i)
    tmp2++;
      mni[i][j] = tmp1;
      wie[i][j] = tmp2;
    }
    //printf("\n");
  }
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(tab[j]<tab[i])
    inw++;
  int liczba = 0, mini = inw;
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(tab[i]>tab[j])
      {
    int wyn = inw  - (mni[tab[j]][j]-mni[tab[j]][i]) + (mni[tab[i]][j]-mni[tab[i]][i]) - (wie[tab[i]][j]-wie[tab[i]][i]) + (wie[tab[j]][j] - wie[tab[j]][i]);
        //printf("%d %d %d\n", i, j, wyn);
    if(wyn<mini)
    {
      mini = wyn;
      liczba = 0;
    }
    if(wyn==mini)
    {
      liczba++;
    }
      }
  printf("%d %d\n", mini, liczba);
  return 0;
}