#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

/*
 *  ........
 *  ...X...X
 *  ........
 *  .X...X..
 *  ........
 *  ...X...X
 *  ........
 *  .X...X..
 */

using namespace std;
static char x[10][10];
static vector <pair <int, int> > KK;

bool test()
{
  KK.clear();
  for(int i=0; i<8; i++)
    scanf(" %s ", x[i]);
  for(int i=0; i<8; i++)
    for(int j=0; j<8; j++)
      if(x[i][j]=='K')
    KK.push_back(make_pair(i,j));
  //printf("%d %d %d %d\n", KK[0].first, KK[0].second, KK[1].first, KK[1].second);
  if(abs(KK[0].first - KK[1].first) % 4 == 0)
  {
    if(abs(KK[0].second - KK[1].second) % 4 == 0)
      return true;
    else
      return false;
  }
  else
    return false;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    puts(test() ? "YES" : "NO");
  return 0;
}