#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

const int MAXN = 1e5 + 2;

using namespace std;

int p[30000];

int main()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
       cin >> p[i];
   }
   for (int i = 1; i <= n; i++)
   {
       vector<int> cnt(30000);
       int id = i;
       while (cnt[id] != 2)
       {
           cnt[id]++;
           if (cnt[id] == 2)
           {
               cout << id << " ";
               break;
           }
           id = p[id];
       }
   }
}