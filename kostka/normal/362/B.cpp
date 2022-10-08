#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXM = 3007;

static int tab[MAXM];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++)
    scanf("%d", &tab[i]);
  sort(tab, tab + m);
  if(tab[0]==1 || tab[m-1]==n)
  {
    puts("NO");
    return 0;
  }
  for(int i=0; i<m-2; i++)
    if(tab[i]+1==tab[i+1] && tab[i+1]+1==tab[i+2])
    {
      puts("NO");
      return 0;
    }
  puts("YES");
  return 0;
}