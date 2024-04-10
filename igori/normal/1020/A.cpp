#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

const int MAXN = 1e5 + 2;

using namespace std;

int main()
{
   int n, h, a, b, k;
   cin >> n >> h >> a >> b >> k;
   for (int i = 0; i < k; i++)
   {
       int na, ha, nb, hb;
       cin >> na >> ha >> nb >> hb;
       if (na == nb)
       {
           cout << abs(ha - hb) << endl;
           continue;
       }
       if (ha > b && hb > b)
       {
           cout << abs(na - nb) + abs(ha - b) + abs(hb - b) << "\n";
           continue;
       }
       if (ha < a && hb < a)
       {
           cout << abs(na - nb) + abs(ha - a) + abs(hb - a) << "\n";
           continue;
       }
       cout << abs(na - nb) + abs(ha - hb) << "\n";
   }
}