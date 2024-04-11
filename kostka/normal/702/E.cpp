#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int LOG = 40;
const int MAXN = 100007;

int dok[LOG][MAXN];
long long war[LOG][MAXN];
int mun[LOG][MAXN];

int jestem[MAXN];
long long wynwar[MAXN];
int wynmin[MAXN];

int main()
{
  int n;
  long long k;
  cin >> n >> k;
  for(int i=0; i<n; i++)
    cin >> dok[0][i];
  for(int i=0; i<n; i++)
  {
    cin >> war[0][i];
    mun[0][i] = war[0][i];
  }
  for(int i=1; i<LOG; i++)
  {
    for(int v=0; v<n; v++)
    {
      dok[i][v] = dok[i-1][dok[i-1][v]];
    }
    for(int v=0; v<n; v++)
    {
      war[i][v] = war[i-1][v] + war[i-1][dok[i-1][v]];
      mun[i][v] = min(mun[i-1][v], mun[i-1][dok[i-1][v]]);
    }
  }
  for(int i=0; i<n; i++)
  {
    jestem[i] = i;
    wynwar[i] = 0;
    wynmin[i] = 1e9;
  }
  int e = 0;
  while(k)
  {
    //cerr << e << "\n";
    if(k%2)
    {
      for(int i=0; i<n; i++)
      {
        wynwar[i] += war[e][jestem[i]];
        wynmin[i] = min(wynmin[i], mun[e][jestem[i]]);
        jestem[i] = dok[e][jestem[i]];
      }
    }
    k /= 2;
    e++;
  }
  for(int i=0; i<n; i++)
    cout << wynwar[i] << " " << wynmin[i] << "\n";
}