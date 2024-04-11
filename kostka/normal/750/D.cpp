//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int n, ile[30];
map <int, int> dx = {{0, 0}, {45, 1}, {90, 1}, {135, 1}, {180, 0}, {225, -1}, {270, -1}, {315, -1}};
map <int, int> dy = {{0, 1}, {45, 1}, {90, 0}, {135, -1}, {180, -1}, {225, -1}, {270, 0}, {315, 1}};
set <pair <int, int>> zaznacz;
const int ST = 200;
bool bylem[30][2*ST+7][2*ST+7][10];

void rek(int x, int y, int poz, int kier = 0)
{
  assert(abs(x) <= ST and abs(y) <= ST);
  kier = (kier%360 + 360)%360;
  if(poz == n)
    return;
  if(bylem[poz][x+ST][y+ST][kier/45])
    return;
  bylem[poz][x+ST][y+ST][kier/45] = true;
  for(int i=0; i<ile[poz]; i++)
  {
    x += dx[kier];
    y += dy[kier];
    zaznacz.insert(make_pair(x,y));
  }
  rek(x, y, poz+1, kier+45);
  rek(x, y, poz+1, kier-45);
}

int main()
{
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> ile[i];
  rek(0, 0, 0);
  cout << (int)zaznacz.size() << "\n";
  return 0;
}