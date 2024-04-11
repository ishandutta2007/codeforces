#include<iostream>

using namespace std;

int tab[] = {1,0,0,1,0,1,0,1,1,1,0,0,1,0,1};

int main()
{
  int n;
  cin >> n;
  cout << tab[n-1];
  return 0;
}